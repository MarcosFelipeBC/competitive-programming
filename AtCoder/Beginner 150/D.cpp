#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b){
	if(b == 0) return a;
	return gcd(b, a%b);
}

const int N = 100007;
long long v[N];

int main(){
	long long n, m;
	scanf("%lld %lld", &n, &m);
	long long mmc = 1LL;
	long long mx = 0;
	for (int i=0; i<n; i++){
		scanf("%lld", &v[i]);
		v[i] /= 2;
		mmc = (mmc * v[i]/gcd(mmc, v[i]));
		if(mmc > m) {
			printf("0\n");
			return 0;
		}
	}

	for(int i = 0; i < n; ++i) {
		long long p2 = mmc/v[i];
		// p2 so pode ser impar
		if(p2%2 == 0) {
			printf("0\n");
			return 0;
		} 
	}

	
	printf("%lld\n", (m/mmc + 1)/2);

}