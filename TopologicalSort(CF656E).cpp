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
const int mxN = 2e5 + 9;
 
int n;
vector<int> adj[mxN]; //undirected egdes
vector<int> dir[mxN]; //directed edges
vector<int> ans;
vector<int> ans2;
vector<bool> vis;

void dfs( int node ){
	vis[node] = true;
	for(auto child: dir[node]){
		if( !vis[child] ) dfs(child);
	}	
	ans.push_back(node);
}

void Topological_sort(){
	//reset
	ans.clear();
	ans2.clear();
	ans2.push_back(-1);
	vis.assign( n+1, false );
	//We use index [0,n];
	
	for(int i=1; i <= n; i++){
		if( !vis[i] ) dfs(i);
	}	
	
	for(int i=(int) ans.size()-1; i >= 0; --i) ans2.push_back(ans[i]);
}
 
void solve(){
	int m,ti,x,y;
	cin >> n >> m;
	
	//reset
	for(int i=1; i <= n; i++) adj[i].clear();
	for(int i=1; i <= n; i++) dir[i].clear();
	
	while(m--){
		cin >> ti >> x >> y;
		if( ti ) dir[x].push_back(y);
		adj[x].push_back(y);	
	}
	
	Topological_sort();		
	
	bool ok = true;
	vector<int> pos(n+1);
	for(int i=1; i <= n; i++) pos[ ans2[i] ] = i;
	
	/*
	for(auto &c: ans2) cout << c << " ";
	cout << "\n";
	for(auto &c: pos) cout << c << " ";
	cout << "\n";
	*/
	
	for(int i=1; i <= n; i++){
		for(auto &c: dir[i]){
			//check directed edge ( i, c )
			if( pos[i] > pos[c] ){
				ok = false;
				break;
			}	
		}	
	}		
	
	if( !ok ) cout << "NO\n";
	else{
		cout << "YES\n";
		for(int i=1; i <= n; i++){
			for(auto &c: adj[i]){
				//pair (i,c)
				if( pos[i] < pos[c] ) cout << i << " " << c << "\n";
				else{
					cout << c << " " << i << "\n";
				}	
			}		
		}	
	}	
	
}	
 
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	
}
 

