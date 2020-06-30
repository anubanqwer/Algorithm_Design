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

ll h[mxN];
ll p[mxN];
int n;
ll A,R,M;

int bin1(ll val){
    //return leftmost index which has the value(h[idx]) exactly equal to val
    int res = -1;
    int L = 1; int R = n;
    while(L <= R){
        int mid = L + (R-L)/2;
        if( h[mid] == val ){
            res = mid;
            R = mid-1;
        }
        else if( h[mid] > val ){
            R = mid-1;
        }
        else if( h[mid] < val ) L = mid+1;
    }
    return res;

}

int bin2(ll val){
    //return the rightmost index which has the value less than val( from the input )
    int res = -1;
    int L = 1; int R = n;
    while(L <= R){
        int mid = L + (R-L)/2;
        if( h[mid] > val ){
            R = mid-1;
        }
        else if( h[mid] < val ) { L = mid+1; res = max(res, mid); }
    }
    return res;
}

ll solve(ll val){
    //assume val is an optimal value
    bool use_bin2 = false;
    int pos = bin1(val);
    //cout << val << " " << pos <<endl;
    if( pos == -1 ) { pos = bin2(val)+1; use_bin2 = true; }
    //cout << pos << endl;


    ll oper1 = (pos-1)*val - p[pos-1];
    ll oper2;
    if( !use_bin2)  oper2 = ( p[n] - p[pos]  )   -  (n-pos)*val;
    else{
        oper2 = ( p[n]-p[pos-1] ) - ( (n-pos+1)*val );
    }
    ll res = min( oper1, oper2 ) * M;
    if( oper1 > oper2 ) res += (oper1-oper2) * A;
    else if( oper1 < oper2 ) res += (oper2-oper1) * R;
    //cout << val << " " << oper1 << " " << oper2 << " " << res << endl;
    return res;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	int tmp;
	cin >> n >> A >> R >> M;
	M = min(A+R, M);
	for(int i=1; i <= n; i++) cin >> h[i];
	sort(h+1,h+n+1);
	for(int i=1; i <= n; i++) p[i] = p[i-1] + h[i];
    ll ans = llm;

    //using ternary search
    //unimodal f(x) in range [a,b]
    
    ll a = h[1]; ll b = h[n];
    while( b-a > ((ll)10) ){
        ll c = a + (b-a)/3;
        ll d = b- (b-a)/3;
        if( solve(c) < solve(d) ) b = d;
        else a = c;
    }
    for(int i=a; i <= b; i++){
        ans = min( ans, solve(i) );
    }

    cout << ans;



}
