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
vector<P> adj[mxN];
vector<int> adj2[mxN];
ll d[mxN];
int vis[mxN], vis2[mxN];

void dfs1(int u, int par){
    vis[u] = 1;
    for(auto &v: adj[u]){
        if( !vis[v[1]] ) dfs1( v[1], u );
    }
}

void dfs2(int u, int par){
    vis2[u] = 1;
    for(auto &v: adj2[u]){
        if( !vis2[v] ) dfs2(v, u);
    }
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	int a,b,c;
	cin >> n >> m;
	for(int i=1; i <= m; i++){
        cin >> a >> b >> c;
        adj[a].push_back( {c,b} );
        adj2[b].push_back(a);
	}
	dfs1(1, -1);
	dfs2(n, -1);

	memset(d, 0xc0, sizeof(d));
	//base case
	d[1] = 0;

    //res is d[n] for (n-1)th iteration
    for(int k=1; k <= n; k++){
        bool arbitrarily = false;
        for(int u=1; u <= n; u++){
            for(auto &c: adj[u]){
                ll cost = c[0], v = c[1];
                if( d[v] < d[u]+cost ){
                    if( vis[v] && vis2[v] ) arbitrarily = true;
                    d[v] = d[u]+cost;
                }
            }
        }
        if( arbitrarily && k > n-1 ){
            cout << -1; return 0;
        }
    }

    cout << d[n];

}
