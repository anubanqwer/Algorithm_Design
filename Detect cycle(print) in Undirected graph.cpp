#include <bits/stdc++.h>
#include <numeric>
#include <iomanip>
#include <functional>
#define ll long long
#define intm INT_MAX
#define llm LLONG_MAX

using namespace std;
//typedef pair<char,int> P;
const ll MOD = 1e9 + 7;
const int mod = 1e9 + 7;
const int mxN = 2e5 + 9;
const int INF = 2e9;

/*
https://codeforces.com/contest/1454/problem/E
*/

vector<int> adj[mxN];

//find cycle (at most 1 cycle)
bool b[mxN];
vector<int> cycle;
stack<int> st;

bool dfs_cycle(int u, int par){
    if(b[u]){
        cycle.push_back(u);
        while(st.top() != u){
            cycle.push_back(st.top());
            st.pop();
        }
        return true;
    }
    else{
        b[u] = true;
        st.push(u);
        for(int v: adj[u]){
            if(v != par && dfs_cycle(v, u)) return true;
        }
        //Done exploring subtree of node u and didn't find any visited node
        //So we delete node u in stack and return false E.g. leaf node
        st.pop();
        return false;
    }
}
//

//dsu
int p[mxN];
int Size[mxN];

int get(int a){
    return p[a] = (p[a]==a ? a : get(p[a]));
}

void unite(int x, int y){
    int a = get(x);
    int b = get(y);
    if( a == b ) return;
    if( Size[a] > Size[b] ) swap(a,b);
    p[a] = b;
    Size[b] += Size[a];
}
//

void solve() {
    int n,x,y;
    cin >> n;
    //preprocessing
    for(int i=1; i <= n; i++){
        adj[i].clear();
        b[i] = false;
        cycle.clear();
        while(!st.empty()) st.pop();
        p[i] = i;
        Size[i] = 1;
    }

    for(int i=1; i <= n; i++){
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs_cycle(1, -1);

    ll ans = 1LL*n*(n-1);
    int N = (int)cycle.size();
    set<pair<int,int>> cycle_edges;
    for(int i=0; i < N; i++){
        cycle_edges.insert({ cycle[i], cycle[(i+1)%N] });
        cycle_edges.insert({ cycle[(i+1)%N], cycle[i] });
    }

    for(int i=1; i <= n; i++){
        for(auto &v: adj[i]){
            pair<int,int> tmp_pair = {i, v};
            if( cycle_edges.find(tmp_pair) == cycle_edges.end() ){
                unite(i, v);
            }
        }
    }

    for(int i=1; i <= n; i++){
        if(i==get(i)) ans -= 1LL*Size[i]*(Size[i]-1)/2;
    }

    cout << ans << '\n';
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);

	int t;
    //t=1;
	cin >> t;
	while(t--){
        solve();
	}



}
