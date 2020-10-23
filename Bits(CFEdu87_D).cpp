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

int n;
int bits[mxN];
//bits start from index 1 to n

void update(int i, int add){
	while( i <= n ){
		bits[i] += add;
		i += i&(-i);
	}
}

int sum(int i){
    //include index i
    //return sum from index[1, i]
	int sm = 0;
	while(i>0){
		sm += bits[i];
		i -= i&(-i);
	}
	return sm;
}


int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	int query_val,tmp,q;
	cin >> n >> q;
	for(int i=1; i <= n; i++){
		cin >> tmp;
		update(tmp, 1);
	}
	while(q--){
		cin >> query_val;
		if( query_val > 0 ) update(query_val, 1);
		else{
			query_val *= -1;
			int low = 1; int high = n;
			int ans = n;
			while( low <= high ){
				int mid = low + (high-low)/2;
				int query_bits = sum(mid);
				if( query_val <= query_bits ){
					ans = mid;
					high = mid-1;
				}
				else{
					low = mid+1;
				}
			}
			update(ans, -1);

		}
	}
	for(int i=1; i <= n; i++){
		if( sum(i) > 0 ){
			cout << i << "\n";
			return 0;
		}
	}
	cout << 0 << "\n";









}
