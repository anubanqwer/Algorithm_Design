//Test git

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
const int mxN = 2e5 + 9;

multiset<int, greater<int> > s[mxN];
int rating[mxN];
int kinder[mxN];
multiset<int> min_of_max;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
    int n,q,a,b,c,newkin;
    cin >> n >> q;
    for(int i=1; i <= n; i++){
        cin >> a >> b;
        rating[i] = a;
        kinder[i] = b;
        s[b].insert(a);
    }
    for(int i=1; i <= 200000; i++){
        if( s[i].size() > 0 ) min_of_max.insert( *(s[i].begin()) );
    }
    while(q--){
        cin >> c >> newkin;
        int rate = rating[c]; int oldkin = kinder[c];
        //erase 2 elements in min_of_max ( the highest rating in oldkin and newkin )
        if( s[newkin].size() > 0 ){
            int highest_newkin = *(s[newkin].begin());
            min_of_max.erase( min_of_max.find( highest_newkin ) );
        }
        if( s[oldkin].size() > 0 ){
            int highest_oldkin = *(s[oldkin].begin());
            min_of_max.erase( min_of_max.find( highest_oldkin ) );
        }

        //move element(rate) from oldkin to newkin
        s[oldkin].erase( s[oldkin].find( rate ) );
        s[newkin].insert(rate);

        //update the maximum value of oldkin and newkin to --> min_of_max
        if( s[oldkin].size() > 0 ) min_of_max.insert( *(s[oldkin].begin()) );
        if( s[newkin].size() > 0 ) min_of_max.insert( *(s[newkin].begin()) );

        //print the ans, update kinder
        kinder[c] = newkin;
        cout << *(min_of_max.begin()) << "\n";
    }

}
