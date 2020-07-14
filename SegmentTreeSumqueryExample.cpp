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
const int mxN = 1e5 + 9;

struct segtree{
    int size;
    vector<ll> sm;

    void init(int n){
        size = 1;
        while( size < n ) { size *= 2; }
        sm.assign( 2*size, 0LL );
    }

    void set(int i, int v){
        set( i, v, 0, 0, size-1 );
    }

    void set(int i, int v, int x, int lx, int rx){
        if( rx-lx == 0 ){
            sm[x] = v;
            return;
        }
        int mid = lx + (rx-lx)/2;
        if( i <= mid ) set(i, v, 2*x+1, lx, mid);
        else{
            set(i, v, 2*x+2, mid+1, rx);
        }
        sm[x] = sm[2*x+1] + sm[2*x+2];
    }

    ll query(int L, int R){
        return query(L, R, 0, 0, size-1);
    }

    ll query( int L, int R, int x, int lx, int rx ){
        //completely outside
        if( lx > R || rx < L ) return 0;
        //completely inside
        if( lx >= L && rx <= R ) return sm[x];
        //otherwise
        int mid = lx + (rx-lx)/2;
        ll sm1 = query( L, R, 2*x+1, lx, mid );
        ll sm2 = query( L, R, 2*x+2, mid+1, rx );
        return sm1+sm2;
    }

}	;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n,m,tmp;
	cin >> n >> m;
	segtree st;
	st.init(n);
	for(int i=0; i < n; i++){
        int v;
        cin >> v;
        st.set(i, v);
	}
	//query
	while(m--){
        int op;
        cin >> op;
        if( op == 1 ){
            int i,v;
            cin >> i >> v;
            st.set(i, v);
        }
        else{
            int L,R;
            cin >> L >> R;
            cout << st.query(L, R-1) << "\n";
        }
	}

}
