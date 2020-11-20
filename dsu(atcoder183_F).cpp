#include <bits/stdc++.h>
#include <numeric>
#include <iomanip>
#define ll long long
#define intm INT_MAX
#define llm LLONG_MAX

using namespace std;
//typedef pair<char,int> P;
//const ll MOD = 1e9 + 7;
const int MOD = 998244353;
const int mod = 1e9 + 7;
const int mxN = 2e5 + 9;
const int INF = 2e9;

int p[mxN];
int Size[mxN];

int get(int a){
    return p[a] = (p[a]==a ? a : get(p[a]));
}

void unite(int x, int y){
    int a = get(x);
    int b = get(y);
    if( a == b ) return;
    if( Size[a] > Size[b] ) swap(a,b);
    p[a] = b;
    Size[b] += Size[a];
}

void solve(){
    int n,q,number,a,b,x,y;
    cin >> n >> q;
    //m1 -> (header of the group, class)
    vector<map<int,int> > m1(n+1);
    for(int i=1; i <= n; i++){
        cin >> x;
        //dsu
        Size[i] = 1;
        p[i] = i;
        //m1
        m1[i][x] = 1;
    }
    while(q--){
        cin >> number;
        if(number==1){
            cin >> a >> b;
            a = get(a); b = get(b);
            if(a!=b){
                //assume Size[a] <= Size[b]
                if(Size[a]>Size[b]) swap(a,b);
                unite(a,b);
                //merge small group to bigger group
                for(auto &c: m1[a]) m1[b][c.first] += c.second;
            }
        }
        else{
            cin >> x >> y;
            cout << m1[get(x)][y] << '\n';
        }
    }
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t;
    t=1;
	//cin >> t;
	while(t--){
        solve();
	}
}

/*
First operation -> copy from smaller map to larger map O(n*logn)
                   merge map until all is in the same group is O(logn)
                   total = O(n*(logn)^2)
Second operation -> normal query of map with Q queries O(Qlogn)
*/
