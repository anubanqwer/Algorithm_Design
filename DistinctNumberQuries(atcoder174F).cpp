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
const int mxN = 5e5 + 9;

int n;
int bits[mxN];
int a[mxN];
int last[mxN];
pair<int,int> query[mxN];

void update(int i, int add){
	while( i <= n ){
		bits[i] += add;
		i += i&(-i);
	}
}

int sum(int i){
	int sm = 0;
	while(i>0){
		sm += bits[i];
		i -= i&(-i);
	}
	return sm;
}

int range_sum(int L, int R){
    if( L == 1 ) return sum(R);
    return sum(R) - sum(L-1);
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	int q;
	cin >> n >> q;
	for(int i=1; i <= n; i++) cin >> a[i];
	memset( last, -1, sizeof(last) );
	map<int,vector<pair<int,int> > > m1;
	map<pair<int,int>, int> ans;
	//sorting m1 by R( right end )
	for(int i=1; i <= q; i++){
        int L,R;
        cin >> L >> R;
        query[i] = make_pair(L, R);
        m1[R].push_back( make_pair(L, R) );
	}

    int start = 1;
    for(auto &c: m1){
        int right_end = c.first;
        for(int i=start; i <= right_end; i++){
            if( last[a[i]] == -1 ){
                last[a[i]] = i;
                update(i, 1);
            }
            else{
                update( last[a[i]], -1 );
                last[a[i]] = i;
                update( last[a[i]], 1 );
            }
        }
        start = right_end + 1;

        for(auto &p: m1[right_end]){
            int L = p.first; int R = p.second;
            ans[ make_pair(L, R) ] = range_sum(L, R);
        }
    }

    for(int i=1; i <= q; i++) cout << ans[ query[i] ] << "\n";




}


