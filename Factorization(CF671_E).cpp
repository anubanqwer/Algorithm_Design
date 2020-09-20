#include <bits/stdc++.h>
#include <numeric>
#include <iomanip>
#define ll long long
#define intm INT_MAX
#define llm LLONG_MAX

using namespace std;
//typedef pair<char,int> P;
const int MOD = 1e9 + 7;
const ll mod = 1e9 + 7;
const int mxN = 2e5 + 9;
const int INF = 2e9;


void solve(){
    int n;
    cin >> n;
    vector<pair<int,int> > factorization;
    int tmp_n = n;
    vector<int> divisor;
    for(int i=2; i <= sqrt(n); i++){
        if( tmp_n % i == 0 ){
            if( tmp_n / i == i ) divisor.push_back(i);
            else{
                divisor.push_back(i);
                divisor.push_back(tmp_n/i);
            }
        }
    }
    //because we didn't iterate i=1
    divisor.push_back(n);
    //not necessary -> sort(divisor.begin(), divisor.end());

    tmp_n = n;
    for(int i=2; i <= sqrt(n); i++){
        if( tmp_n % i == 0 ){
            int cnt = 0;
            while( tmp_n%i == 0 ){
                ++cnt;
                tmp_n /= i;
            }
            factorization.push_back( {i, cnt} );
        }
    }
    //don't forget the following line
    //n = 6, i = 2, n/i = 3
    //6 = [ {2,1}, {3,1} ]
    if( tmp_n > 1 ) factorization.push_back( {tmp_n,1 } );



    int N = (int) factorization.size();
    set<int> border;
    vector<int> v_border;
    for(int i=0; i < N-1; i++){
        border.insert( factorization[i].first * factorization[i+1].first );
        v_border.push_back( factorization[i].first * factorization[i+1].first );
    }
    border.insert( factorization[0].first*factorization[N-1].first );
    v_border.push_back( factorization[0].first*factorization[N-1].first );
    vector<bool> b( (int) divisor.size(), false );

    /*for(auto &c: factorization) cout << c.first << " " << c.second << "  factor\n";
    cout << "\n";
    for(auto &c: border) cout << c << " ";
    cout << "\n";
    for(auto &c: divisor) cout << c << " ";
    cout << "\n";*/

    if( N == 1 ){
        int x = factorization[0].first;
        int tmp = x;
        cout << x << " ";
        for(int i=2; i <= factorization[0].second; i++){
            tmp *= x;
            cout << tmp << " ";
        }
        cout << "\n";
        cout << "0\n";
        return;
    }

    if( N == 2 ){
        if( max( factorization[0].second , factorization[1].second ) >= 2 ){
            border.insert(n);
            v_border[1] = n;
        }
        else{
            int aa = factorization[0].first; int bb = factorization[1].first;
            cout <<  aa << " " << aa*bb << " " << bb << "\n";
            cout << "1\n";
            return;
        }
    }


        int j = 0;
        for(auto &c: factorization){
            int a = c.first;
            for(int i=0; i < (int) divisor.size(); i++){
                if( !b[i] && divisor[i]%a == 0 && (  border.find( divisor[i] ) == border.end() ) ){
                    b[i] = true;
                    cout << divisor[i] << " ";
                }
            }
            cout << v_border[j] << " ";
            ++j;
        }

        cout << "\n";
        cout << "0\n";

}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t;
    //t=1;
	cin >> t;
	while(t--){
        solve();
	}



}
