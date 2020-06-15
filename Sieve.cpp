#include <bits/stdc++.h>
#include <numeric>
#include <iomanip>
#define ll long long
#define intm INT_MAX
#define llm LLONG_MAX

using namespace std;
const int MOD = 998244353;
const ll mod = 1e9 + 7;
const int mxN = 1e5 + 9;

vector<int> smallest_factor;
vector<bool> primes;
vector<int> prime_factors;
//prime_factors contain all prime numbers which can divide n.

void sieve(int maximum){
    //n can be maximum about 1e7
    //time complexity is approximately O(n)
    maximum = max(maximum, 2);
    smallest_factor.assign( maximum+1, 0 );
    //firstly we assume all number is prime.
    primes.assign( maximum+1, true );
    primes[1] = primes[0] = false;
    prime_factors = {};

    for(int i=2; i <= maximum; i++){
        if( primes[i] ){
            smallest_factor[i] = i;
            //smallest factor of prime number is itself.
            prime_factors.push_back(i);
            for( ll j = ((ll)i * (ll)i); j <= maximum; j += i ){
                if( primes[j] ){
                    primes[j] = false;
                    smallest_factor[j] = i;
                    //Because j is multiple of i.
                }
            }
        }
    }
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	sieve(n);
    /*
	//Test
	//n = 1000;
	cout << smallest_factor[6] << "\n";
	cout << smallest_factor[13] << "\n";
	cout << smallest_factor[91] << "\n";
	cout << smallest_factor[265] << "\n";
	*/
}
