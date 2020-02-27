#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;

typedef long long ll;

ll fastexp(ll base, ll e){
	if(e == 0) return 1LL;
	if(e == 1) return base;
	ll val = fastexp(base, e/2);
	val = (val%mod * val%mod)%mod;
	if(e & 1) val = (val%mod * base%mod)%mod;
	return val;
}

int gcd(int a, int b){
	if(b == 0) return a;
	return gcd(b, a%b);
}

bool isPrime(int p){
	for (int i=2; i*i<=p; i++){
		if(p%i == 0) return false;
	}
	return true;
}

vector < int > getPrimes(int x){
	vector < int > primes;
	for (int i=2; i*i<=x; i++){
		if(x%i == 0){
			if(isPrime(i)) primes.push_back(i);
			if(x/i != i){
				if(isPrime(x/i)) primes.push_back(x/i);
			}
		}
	}
	if(isPrime(x)) primes.push_back(x);
	return primes;
}

int main(){
	int x;
	ll n;
	cin >> x >> n;
	vector < int > primes = getPrimes(x);
	long long ans = 1LL;
	for (int i=0; i<primes.size(); i++){
		ll p = primes[i];
		ll auxp = p;
		long long qtd = n/auxp;
		while (ceil((double)n/auxp) >= p){
			auxp *= p;
			qtd += (n/auxp);
		}
		ans = (ans%mod * fastexp(p, qtd)%mod)%mod;
	}
	cout << ans << endl;
	return 0;
}