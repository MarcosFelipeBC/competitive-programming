#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;

long long f(int n){
	if(n == 1) return 1;
	long long ans = 2, ant = 2, ant2 = 1;
	for (int i=2; i<n; i++){
		ans = ant + ant2;
		ant2 = ant;
		ant = ans;
		ans %= mod;
		ant %= mod;
		ant2 %= mod;
	}
	return ans;
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	printf("%lld\n", 2LL*((f(n)+f(m)-1)+mod)%mod);
}