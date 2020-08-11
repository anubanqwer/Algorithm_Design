#include <bits/stdc++.h>
#include <numeric>
#include <iomanip>
#define ll long long
#define intm INT_MAX
#define llm LLONG_MAX

using namespace std;
typedef pair<int,int> P;
const int MOD = 1e9 + 7;
const ll mod = 1e9 + 7;
const int mxN = 2e5 + 9;

vector<int> adj[mxN];
int d[mxN];
int n;
int ans[mxN];

void dfs(int u, int par){
    for(auto &v: adj[u]){
        if( v == par ) continue;
        dfs( v,u );
        d[u] = max( d[u], d[v] + 1 ) ;
    }
}

void dfs2( int u, int par, int pd ){
    ans[u] = max( pd, d[u] );
    vector<pair<int,int> > v1;
    v1.push_back({pd, -1});
    for(auto &v: adj[u]){
        if( v == par ) continue;
        v1.push_back( {d[v]+1, v} );
    }
    //v1.push_back( {0, -1} );
    sort(v1.begin(), v1.end(), greater<pair<int,int> >() );
    for(auto &v: adj[u]){
        if( v == par ) continue;
        int pos = 0;
        if( v == v1[0].second ) ++pos;
        dfs2( v, u, v1[pos].first + 1 );
    }
}



int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for(int i=1; i <= n-1; i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
	}
    dfs(1, -1);
    dfs2(1, -1, 0);
    for(int i=1; i <= n; i++) cout << ans[i] << " ";







}
