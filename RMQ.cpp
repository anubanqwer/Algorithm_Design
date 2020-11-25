#include <bits/stdc++.h>
#include <numeric>
#include <iomanip>
#include <functional>
#define ll long long
#define intm INT_MAX
#define llm LLONG_MAX

using namespace std;
//typedef pair<char,int> P;
const ll MOD = 1e9 + 7;
const int mod = 1e9 + 7;
const int mxN = 2e5 + 9;
const int INF = 2e9;

/*
https://codeforces.com/contest/1454/problem/F
*/

struct RMQ{
    vector<vector<int>> rmq;
    int N,largest_bit;

    void init(vector<int> &a){
        this->N = (int)a.size();
        this->largest_bit = (int)floor(log2(float(N)));
        rmq.resize(largest_bit+1);
        for(int i=0; i <= largest_bit; i++){
            rmq[i].resize( N-(1<<i)+1 );
        }

        for(int i=0; i < N; i++) rmq[0][i] = a[i];

        for(int level=1; level <= largest_bit; level++){
            for(int i=0; i+(1<<level) <= N; i++){
                rmq[level][i] = min( rmq[level-1][i], rmq[level-1][i+(1<<(level-1))] );
            }
        }
    }

    void debug(){
        cout << "------------------\n";
        for(int i=0; i <= largest_bit; i++){
            cout << "bit = " << i << "   ";
            for(auto &c: rmq[i]) cout << c << " ";
            cout << '\n';
        }
        cout << "------------------\n";
    }

    //query [0,N-1]
    int query(int L, int R){
        int proper_bit = (int)floor(log2(float(R-L+1)));
        return min( rmq[proper_bit][L], rmq[proper_bit][R-(1<<proper_bit)+1] );
    }
};


void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &c: a) cin >> c;
    RMQ rmq;
    rmq.init(a);
    //rmq.debug();

    vector<int> prefix_max(n, -INF);
    vector<int> suffix_max(n, -INF);
    prefix_max[0] = a[0];
    suffix_max[n-1] = a[n-1];
    for(int i=1; i < n; i++) prefix_max[i] = max(prefix_max[i-1], a[i]);
    for(int i=n-2; i >= 0; --i) suffix_max[i] = max(suffix_max[i+1], a[i]);

    for(int b=n-1; b >= 2; --b){
        int val = suffix_max[b];
        int L = int(lower_bound(prefix_max.begin(), prefix_max.begin()+b, val) - prefix_max.begin());
        //val in prefix range(1st sub array) isn't exist
        if( a[L] != val ) continue;
        int R = int(upper_bound(prefix_max.begin(), prefix_max.begin()+b, val) - prefix_max.begin());

        //at least Size=1 for 2nd sub array (index b-1)
        R = min(R-1, b-2);
        if( L > R ) continue;

        //binary search for proper second sub array
        while(L<=R){
            int mid = L+(R-L)/2;
            //Assume mid is the last index of the first sub array
            assert(mid+1 <= b-1);
            int minSecondArray = rmq.query(mid+1, b-1);
            if( minSecondArray == val ){
                int x = mid+1;
                //3rd -> [b,n-1] Size = (n-1-b+1)
                int z = n-b;
                int y = n-x-z;
                cout << "YES\n";
                cout << x << " " << y << " " << z << "\n";
                return;
            }
            else if( minSecondArray < val ) L = mid+1;
            else{
                R = mid-1;
            }
        }
    }
    cout << "NO\n";
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    //t=1;
    cin >> t;
    while(t--){
        solve();
    }
}
