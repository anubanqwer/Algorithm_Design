#include <bits/stdc++.h>
#include <numeric>
#include <iomanip>
#define ll long long
#define intm INT_MAX
#define llm LLONG_MAX

using namespace std;
typedef array<ll, 2> P;
const int MOD = 1e9 + 7;
const ll mod = 1e9 + 7;
const int mxN = 1e5 + 9;

int n,m;
ll d[509][509];

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	int a,b,q;
	ll c;
	cin >> n >> m >> q;
	memset(d, 0x3f, sizeof(d));
	for(int i=1; i <= m; i++){
        cin >> a >> b >> c;
        d[a][b] = min( d[a][b], c );
        d[b][a] = min( d[b][a], c );
	}
	for(int i=1; i <= n; i++) d[i][i] = 0;

	for(int k=1; k <=n ; k++){
        for(int i=1; i <= n; i++){
            for(int j=1; j <= n; j++){
                d[i][j] = min( d[i][j], d[i][k] + d[k][j] );
            }
        }
	}

	while(q--){
        cin >> a >> b;
        cout << (d[a][b] > 1e18 ? -1 : d[a][b] ) << "\n";
	}



}
