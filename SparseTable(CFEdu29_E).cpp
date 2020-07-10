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
//ar in this problem is a prefix sum array
int ar[mxN];
int leftquery[mxN];
int rightquery[mxN];
map<int,int> idx;
 
void PreLog(int n){
	Log[1] = 0;
	for(int i=2; i <= n; i++) Log[i] = Log[i/2] + 1;
}

void SparseTable(int n){
	for(int i=0; i < n; i++) sp[i][0] = ar[i];
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
 
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	set<int> s1;
	for(int i=0; i < n; i++){
		cin >> leftquery[i] >> rightquery[i];
		s1.insert(leftquery[i]);
		s1.insert(rightquery[i]);
		s1.insert(rightquery[i]+1);
	}	
	int dummy = 0;
	for(auto &c: s1){
		idx[c] = dummy;
		++dummy;
	}
	for(int i=0; i < n; i++){
		int left = idx[leftquery[i]];
		int right = idx[rightquery[i]];
		ar[left] += 1;
		ar[right+1] -= 1;
	}	
	for(int i=1; i < dummy; i++) ar[i] += ar[i-1];
	PreLog(n);
	SparseTable(n);
	for(int i=0; i < n; i++){
		int left = idx[leftquery[i]];
		int right = idx[rightquery[i]];
		//cout << "RMQ Parameters = " << left << " " << right << "\n";
		int mn = RMQ(left, right);
		//cout << "mn = " << mn << "\n";
		if( mn > 1 ){
			cout << i+1 << "\n";
			return 0;
		}	
	}
	cout << -1 << "\n";	
	
	
	
	
 
 
 
}
