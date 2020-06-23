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

ll fact[mxN];

int mult(int a, int b){
    ll a1 = ((ll) a)% MOD;
    ll b1 = ((ll) b)% MOD;
    return (int) ((a1*b1)%MOD);
}

int pow(int a, int b){
    int res = 1;
    while( b > 0 ){
        if( b%2 == 1 ) res = mult(res, a);
        a = mult(a, a);
        b /= 2;
    }
    return res;
}

int inv(int n){
    return pow(n, MOD-2);
}

int nCr(int n, int r){
    if( n < r ) return 0;
    return mult( fact[n] , inv( mult(fact[r], fact[n-r]) ) );
}

int subt( int a, int b ){
    return (((a-b)%MOD) + MOD ) % MOD;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n,k;
	cin >> n >> k;
	fact[0] = fact[1] = 1;
	for(ll i = 2; i <= n; i++) fact[i] = (fact[i-1]*i)%MOD;
	int ans = 0;
	for(int i=1; i <= n; i++){
        int d = n/i;
        ans = ( ans +  ( nCr( d-1, k-1 ) )%MOD ) % MOD;
	}
	cout << ans << "\n";


}
