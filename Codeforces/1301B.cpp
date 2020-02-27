#include <bits/stdc++.h>
using namespace std;

const int N = 500005;
long long vet[N];
int n;


int main(){
	int t;
	scanf("%d", &t);
	while (t-- > 0){	
		scanf("%d", &n);
		long long sum = 0LL;
		long long qtd = 0LL;
		long long mx = 0, mn = 1000000000;
		for (int i=0; i<n; i++){
			scanf("%lld", &vet[i]);
		}
		for (int i=0; i<n; i++){
			if(vet[i] == -1) continue ;
			if((i != 0 && vet[i-1] == -1) || (i+1 < n && vet[i+1] == -1)){
				mx = max(mx, vet[i]);
				mn = min(mn, vet[i]);
			}
		}
		long long k = (mx+mn)/2LL;
		long long ans = 0;
		for (int i=0; i<n; i++){
			if(vet[i] == -1) vet[i] = k;
			if(i) ans = max(ans, abs(vet[i]-vet[i-1]));
		}
		printf("%lld %lld\n", ans, k);
	}
}