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
 
const ll M = pow(2,17);
int seg[4*mxN+9][29];
//we use [0,25]
string s;
 
void update( int idx, int newC, int oldC ){
    //newC and oldC should be in range [0,25]
    seg[idx][newC] += 1;
    seg[idx][oldC] -= 1;
    if( idx != 0 ) update( (idx-1)/2, newC, oldC );
 
}
 
void query(int idx, int ans[], int leftmost, int rightmost, int L, int R){
    //query is in range[L,R]
    //1. totally disjoint
    if( rightmost < L || R < leftmost  ) return;
 
    //2. totally in range
    if( L <= leftmost && rightmost <= R ){
        for(int j=0; j < 26; j++) ans[j] += seg[idx][j];
        return;
    }
 
    //3. intersection
    int mid = leftmost + (rightmost-leftmost)/2;
    query( 2*idx+1, ans, leftmost, mid, L, R );
    query( 2*idx+2, ans, mid+1, rightmost, L, R );
}
 
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
    int q,x,y,z;
    char NEWCHA;
    cin >> s >> q;
 
    //update all char in string to SegmentTree
    for(int i=0; i < s.length(); i++) update(M-1+i, s[i]-'a', 27);
    //
 
    while(q--){
        cin >> x;
        if( x == 1 ){
            cin >> y >> NEWCHA;
            --y;
            if( s[y] != NEWCHA ){
                update(M-1+y, NEWCHA-'a', s[y]-'a');
                s[y] = NEWCHA;
            }
        }
        else if( x == 2 ){
            cin >> y >> z;
            --y; --z;
            int ans[28];
            memset(ans, 0, sizeof(ans));
            query( 0, ans, 0, M-1, y, z );
            int q_ans = 0;
            for(int j=0; j < 26; j++){
                if( ans[j] ) q_ans += 1;
            }
            cout << q_ans << "\n";
        }
    }
 
 
 
}
