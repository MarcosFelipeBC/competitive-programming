#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
int vet[N];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i=0; i<n; i++){
		scanf("%d", &vet[i]);
	}
	for (int i=0; i<n; i++){
		int x;
		scanf("%d", &x);
		vet[i] -= x;
	}
	long long ans = 0LL;
	sort(vet, vet+n);
	for (int i=0; i<n; i++){
		int pos = upper_bound(vet, vet+n, -vet[i]) - vet;
		ans += (long long)(n - pos);
		if(pos < i) ans--;
	}
	printf("%lld\n", ans/2);
}