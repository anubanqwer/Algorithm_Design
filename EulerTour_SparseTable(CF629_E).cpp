//Wrong answer on test55
//Waiting for debugging

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
const int mxN = 1e6 + 9;
 
int Log[mxN];
int sp[mxN][21];
vector<int> adj[mxN];
//for BFS
bool vis[mxN];
int distance_from_root[mxN];
//SparseTable + EulerTourTransversal
vector<int> euler_tour;
vector<int> first_encounter;
vector<int> new_to_old;
//map (real node from the problem) to (euler tour node)
map<int,int> m1;
//map vice versa = m2
map<int,int> m2;

void dfs_euler_tour( int v, int p ){
	int new_index = new_to_old.size();
	//map
	m1[v] = new_index;
	
	new_to_old.push_back(v);
	first_encounter.push_back( euler_tour.size() );
	euler_tour.push_back(new_index);

	for(auto &child: adj[v]){
		if( child != p ){
			dfs_euler_tour( child, v );
			euler_tour.push_back(new_index);
		}
	}
	
}

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
				qq.push(child);
				distance_from_root[child] = distance_from_root[now] + 1;
			} 
		}
	}
}
 

void PreLog(int n){
	//create new global array Log
	Log[1] = 0;
	for(int i=2; i <= n; i++) Log[i] = Log[i/2] + 1;
}

void SparseTable(int n){
	//create new global array ar
	for(int i=0; i < n; i++) sp[i][0] = euler_tour[i];
	for(int j=1; (1<<j) <= n; j++){
		for(int i=0; i + (1<<j)-1 < n; i++){
			sp[i][j] = min( sp[i][j-1], sp[i+ (1<<(j-1)) ][j-1] );
		}	
	}	
}

int RMQ(int leftmost, int rightmost){
	int k = Log[rightmost-leftmost+1];
	return min( sp[leftmost][k], sp[rightmost - (1<<k) + 1 ][k] );
}

int LCA(int x, int y){
	int x1 = first_encounter[m1[x]];
	int y1 = first_encounter[m1[y]];
	//assume x1 <= y1
	if( x1 > y1 ) swap(x1, y1);
	int mn = RMQ( x1, y1 );
	//map from (euler_tour) to (real node from the problem)
	return m2[mn];
}
 
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n,q,a,b,tmp;
	cin >> n >> q;
	for(int i=0; i < n-1; i++){
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	BFS();
	//SparseTable + EulerTour
	dfs_euler_tour(1, -1);
	PreLog( euler_tour.size()  );
	SparseTable( euler_tour.size()  );
	//map m2
	for(auto &c: m1) m2[c.second] = c.first;
	
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
			if( LCA(deepest_node, c) != 1 ) continue;
			if( distance_from_root[c] > 1 ){
				ok = false;
				break;
			}
		}
		cout << ( ok ? "YES\n" : "NO\n" );
	}
	/*
	//test
	for(int i=0; i < 11; i++) cout << distance_from_root[i] << " ";
	cout << "\n";
	//
	for(auto &c: euler_tour) cout << c << " ";
	cout << "\n";
	cout << "Startmap\n";
	for(auto &c: m1) cout << c.first << " " << c.second << "\n";
	//
	for(int i=0; i < 11; i++) cout << first_encounter[i] << " ";
	cout << "\n";
	//
	cout << LCA(8,9) << "\n"; //ans should be 7
	cout << LCA(6,9) << "\n"; //ans shoule be 1
	*/
}
