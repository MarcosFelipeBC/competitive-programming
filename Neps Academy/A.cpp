//https://neps.academy/contest/215/problem/676

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 200005;
ll vet[N];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i=0; i<n; i++){
		scanf("%lld", &vet[i]);	
	}
	sort(vet, vet+n);
	ll ans = vet[n-1]*vet[n-2]*vet[n-3];
	ans = max(ans, vet[0]*vet[1]*vet[n-1]);
	printf("%lld\n", ans);
}