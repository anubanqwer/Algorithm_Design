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

// The highest priority is the second value of pair, sort it by descending order
// Then, the second value of pair is equal, we check sort the first value of pair by descending order too.

struct Order
{
    bool operator()(P const& a, P const& b) const
    {
        return a.second > b.second || a.second == b.second && a.first > b.first;
    }
};


int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	priority_queue< P, vector<P>, Order > PQ;
	PQ.push( {5,2} );
	PQ.push( {3,2} );PQ.push( {3,7} );
	PQ.push( {10,1} );
	PQ.push( {9,8} );

	while( !PQ.empty() ){
        cout << PQ.top().first << " " << PQ.top().second << endl;
        PQ.pop();
	}
}
