#include <bits/stdc++.h>
#include <numeric>
#include <iomanip>
#define ll long long
#define intm INT_MAX
#define llm LLONG_MAX

using namespace std;
//typedef pair<int,int> P;
const int MOD = 1e9 + 7;
const ll mod = 1e9 + 7;
const int mxN = 2e5 + 9;

vector<int> adj[mxN];
int d[mxN];
int n;
int anc[mxN][19];
//0-18

void dfs(int u, int par, int depth){
    d[u] = depth;
    anc[u][0] = par;
    for(int i=1; i < 19; i++)
        anc[u][i] = d[u] - (1<<i) >= 0 ? anc[anc[u][i-1]][i-1] : -1;
    for(auto &v: adj[u]){
        if( v == par ) continue;
        dfs( v,u, depth+1 );
    }
}

int lca(int p, int q){
    //p's height is lower or equal to q's height.
    if( d[q] > d[p] ) swap(p,q);
    for(int i=18; ~i; --i){
        if( d[p] - (1<<i) >= d[q] ) p = anc[p][i];
    }

    if( p == q ) return p;
    for(int i=18; ~i; --i){
        int x = anc[p][i];
        int y = anc[q][i];
        if( x^y ){
            p = anc[p][i]; q = anc[q][i];
        }
    }
    return anc[p][0];
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	int q;
	cin >> n >> q;
	for(int i=2; i <= n; i++){
        int a;
        cin >> a;
        adj[a].push_back(i);
        adj[i].push_back(a);
	}
    dfs(1, -1, 0);
    while(q--){
        int x,y;
        cin >> x >> y;
        cout << lca(x,y) << "\n";
    }




}
