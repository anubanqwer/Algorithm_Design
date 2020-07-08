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

char ar[7][7];

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	int H,K,W;
	string s;
	cin >> H >> W >> K;
	for(int i=0; i < H; i++){
        cin >> s;
        for(int j=0; j < W; j++) ar[i][j] = s[j];
	}
	ll ans = 0;
	for(int i=0; i < (1<<H); i++){
        for(int j=0; j < (1<<W); j++){
            int cnt = 0;
            for(int i2 = 0; i2 < H; i2++){
                for(int j2 = 0; j2 < W; j2++){
                    if( (i>>i2)&1 ) continue;
                    if( (j>>j2)&1 ) continue;
                    if( ar[i2][j2] == '#' ) ++cnt;
                }
            }
            if( cnt == K ) ++ans;
        }
	}
	cout << ans << "\n";
}
