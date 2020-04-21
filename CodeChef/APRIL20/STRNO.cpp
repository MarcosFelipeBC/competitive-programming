#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

vector < int > primes;
bitset < N > isPrime;

void sieve()
{
	isPrime.set();
	isPrime[0] = isPrime[1] = 0;
	for (int i=2; i<N; i++){
		if(isPrime[i]){
			for (int j=i+i; j<N; j+=i){
				isPrime[j] = 0;
			}
			primes.push_back(i);
		}
	}
}

int main()
{
	sieve();
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int x, k;
		scanf("%d %d", &x, &k);
		if(k >= 30) puts("0");
		else {
			int pos = 0;
			int cnt = 0;
			for (int i=0; (long long)primes[i] * primes[i] <= x; i++){
				while (x%primes[i] == 0){
					x /= primes[i];
					cnt++;
				}
			}
			if(x != 1) cnt++;
			if(cnt >= k) puts("1");
			else puts("0");
		}
	}
}