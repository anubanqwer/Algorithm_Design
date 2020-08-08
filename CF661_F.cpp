#include <bits/stdc++.h>
#include <numeric>
#include <iomanip>
#define ll long long
#define intm INT_MAX
#define llm LLONG_MAX

using namespace std;
typedef pair<int,int> P;
const int MOD = 998244353;
const ll mod = 1e9 + 7;
const int mxN = 1e5 + 9;

struct seg{
    int l,r;
};

void solve(){
    int n;
    cin >> n;
    vector<seg> v1;
    for(int i=1; i <= n; i++){
        int a,b;
        cin >> a >> b;
        seg tmp;
        tmp.l = a; tmp.r = b;
        v1.push_back( tmp );
    }
    //extra one
    seg tmp2;
    tmp2.l = 1; tmp2.r = 200009;
    v1.push_back(tmp2);

    sort( v1.begin(), v1.end(),[]( seg a, seg b ){
        if( a.r != b.r ) return a.r < b.r;
        return a.l > b.l;
    } );

    vector<vector<int> > inside(n+1);
    for(int i=0; i <= n; i++){
        for(int j=0; j < i; j++){
            if( v1[i].l <= v1[j].l && v1[j].r <= v1[i].r ) inside[i].push_back(j);
        }
    }

    vector<int> cnt_inside(n+1);
    for(int i=0; i <= n; i++){
        int m = (int) inside[i].size();
        //base case
        if( m == 0 ){ cnt_inside[i] = 0; continue; }
        if( m == 1 ){ cnt_inside[i] = 1; continue; }

        vector<int> dp(m, 1);
        for(int j=0; j < m; j++){
            dp[j] += cnt_inside[ inside[i][j] ];
            int L = 0; int R = j-1; int ans = -1;
            while(L<=R){
                int mid = L + (R-L)/2;
                if( v1[inside[i][mid] ].r < v1[inside[i][j] ].l ){
                    ans = mid;
                    L = mid+1;

                }
                else{ R = mid-1; }
            }
            if( ans != -1 ) dp[j] += dp[ans];
            if( j > 0 ) dp[j] = max( dp[j], dp[j-1] );
        }
        cnt_inside[i] = dp[m-1];
    }

    cout << cnt_inside[n] << "\n";

}


int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t;
	cin >> t;
	while(t--){
        solve();
	}

}


