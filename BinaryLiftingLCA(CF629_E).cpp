This code have a bug. Edited 11/8/2020

#include <bits/stdc++.h>
#include <numeric>
#include <iomanip>
#define ll long long
#define intm INT_MAX
#define llm LLONG_MAX
 
using namespace std;
//typedef pair<int,int> P;
const int MOD = 998244353;
const ll mod = 1e9 + 7;
const int mxN = 1e6 + 9;
  
//store edges
vector<int> adj[mxN];
//for BFS
bool vis[mxN];
int distance_from_root[mxN];
int par[mxN];
//LCA
int n;
int P[mxN][21];

void BFS(){
	queue<int> qq;
	qq.push(1);
	distance_from_root[1] = 0;
	vis[1] = true;
	while( !qq.empty() ){
		int now = qq.front();
		qq.pop();
		vis[now] = true;
		for(auto child: adj[now]){
			if( !vis[child] ){
				par[child] = now;
				qq.push(child);
				distance_from_root[child] = distance_from_root[now] + 1;
			} 
		}
	}
}

void preprocess(){
	for(int i=1; i <= n; i++){
		for(int j=0; (1<<j) < n; j++){
			P[i][j] = -1;
		}	
	}
	
	for(int i=1; i <= n; i++) P[i][0] = par[i];
	
	for(int j=1; (1<<j) < n; j++){
		for(int i=1; i <= n; i++){
			if( P[i][j-1] != -1 ) P[i][j] = P[ P[i][j-1] ][j-1];
		}	
	}	
}

int LCA(int p, int q){
	//assume p is lower than q
	if( distance_from_root[p] < distance_from_root[q] ) swap(p,q);
	
	int log = floor( log2( distance_from_root[p] ) );
	
	//find ancestor of p which is situated on the same level with q
	for(int i=log; i >= 0; --i){
		if( distance_from_root[p] - (1<<i) >= distance_from_root[q] ) p = P[p][i];
	}	
	
	//q is an ancestor of p
	if( p == q ) return q;
	
	for(int i=log; i >= 0; --i){
		if( P[p][i] != -1 && P[p][i] != P[q][i] ){
			p = P[p][i];
			q = P[p][i];
		}	
	}	
	return par[p];
	
}
 
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	int q,a,b,tmp;
	cin >> n >> q;
	for(int i=0; i < n-1; i++){
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	BFS();
	par[1] = -1;
	preprocess();
	
	while(q--){
		cin >> n;
		vector<int> v1;
		for(int i=0; i < n; i++){
			cin >> tmp;
			v1.push_back(tmp);
		}
		int deepest_node = 1;
		for(auto &c: v1){
			if( distance_from_root[c] > distance_from_root[deepest_node] ) deepest_node = c;
		}
		bool ok = true;
		for(auto &c: v1){
			int low_anscestor = LCA(deepest_node, c);
			if( low_anscestor != 1 ){
				if( distance_from_root[c] - distance_from_root[low_anscestor] > 1 ){
					ok = false;
					break;
				}
			}	
			else{
				if( distance_from_root[c] > 1 ){
					ok = false;
					break;
				}
			}
		}
		cout << ( ok ? "YES\n" : "NO\n" );
	}
	
}
