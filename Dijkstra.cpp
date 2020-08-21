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
ll d[mxN];

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	int a,b,c;
	cin >> n >> m;
	for(int i=1; i <= m; i++){
        cin >> a >> b >> c;
        adj[a].push_back( {c,b} );
	}
	memset(d, 0x3f, sizeof(d));
	priority_queue<P, vector<P>, greater<P> > pq;
	pq.push( {0, 1} );
	d[1] = 0;
	while(!pq.empty()){
        P u = pq.top();
        pq.pop();
        if( u[0] > d[u[1]] ) continue;
        for(auto v: adj[u[1]]){
            if( u[0] + v[0] < d[v[1]] ){
                d[v[1]] = u[0] + v[0];
                pq.push( { d[v[1]], v[1] } );
            }
        }
	}

	for(int i=1; i <= n; i++) cout << d[i] << " ";

}
