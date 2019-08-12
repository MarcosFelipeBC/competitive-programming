#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 100005;
ll vet[N];

int main(){
	int n;
	scanf("%d", &n);
	for (int i=0; i<n; i++){
		scanf("%lld", &vet[i]);
		if(i) vet[i] += vet[i-1];
	}
	ll sum = vet[n-1];
	if(sum%3 != 0) {
		puts("Nao :)");
		return 0;
	}
	ll ans = 0LL;
	ll qtd = 0LL;
	for (int i=0; i<n; i++){
		if(vet[i] == sum/3) qtd++;
		if(vet[i] == 2*sum/3) ans += qtd;
	}
	if(ans != 0) puts("Sim :(");
	else puts("Nao :)");
}
