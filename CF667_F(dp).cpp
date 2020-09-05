#include <bits/stdc++.h>
#include <numeric>
#include <iomanip>
#define ll long long
#define intm INT_MAX
#define llm LLONG_MAX

using namespace std;
//typedef pair<char,int> P;
const int MOD = 1e9 + 7;
const ll mod = 1e9 + 7;
const int mxN = 2e5 + 9;
const int INF = 2e9;

int dp[209][209][209];
//(length, replacement, t[0])

void solve(){
    int n,limited;
    string s,t;
    cin >> n >> limited >> s >> t;

    //special case
    if( t[0] == t[1] ){
        int cnt = 0;
        for(int i=0; i < n; i++){
            if( s[i] == t[0] ) ++cnt;
        }
        int x = min( cnt+limited, n );
        cout << 1LL*x*(x-1)/2 << "\n";
        return;
    }

    for(int i=0; i <= n; i++){
        for(int j=0; j <= limited; j++){
            for(int k=0; k <= n; k++){
                dp[i][j][k] = -INF;
            }
        }
    }

    //base case for i=1
    if( s[0] == t[0] ){
        dp[0][0][1] = 0;
    }
    else if( s[0] == t[1] ){
        dp[0][0][0] = 0;
        //change to a
        dp[0][1][1] = 0;
    }
    else{
       dp[0][0][0] = 0;
       //change to a
       dp[0][1][1] = 0;
    }

    for(int i=1; i < n; i++){
        for(int j=0; j <= limited; j++){
            for(int k=0; k <= n; k++){
                //don't change anything ( j is still the same )
                if( s[i] == t[0] ){
                    if( i-1 >= 0 && k-1 >= 0 ) dp[i][j][k] = max( dp[i-1][j][k-1], dp[i][j][k] );
                }
                else if( s[i] == t[1] ){
                    if( i-1 >= 0 ) dp[i][j][k] = max( dp[i-1][j][k] + k, dp[i][j][k] );
                }
                else{
                    if( i-1 >= 0 ) dp[i][j][k] = max( dp[i-1][j][k], dp[i][j][k] );
                }

                //change s[i] to t[0]
                if( s[i] != t[0] ){
                    if( i-1 >= 0 && j-1 >= 0 && k-1 >= 0 ) dp[i][j][k] = max( dp[i-1][j-1][k-1], dp[i][j][k] );
                }

                //change s[i] to t[1]
                if( s[i] != t[1] ){
                    if( i-1 >= 0 && j-1 >= 0 ) dp[i][j][k] = max( dp[i-1][j-1][k] + k, dp[i][j][k] );
                }
            }
        }
    }
    int ans = 0;
    for(int j=0; j <= limited; j++){
        for(int k=0; k <= n; k++){
            ans = max( ans, dp[n-1][j][k] );
        }
    }
    cout << ans << "\n";

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
