//https://atcoder.jp/contests/abc133/tasks/abc133_d

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
long long vet[MAXN], ans[MAXN];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i=0; i<n; i++){
		scanf("%lld", &vet[i]);
		if(i%2 == 0) ans[0] += vet[i];
		else ans[0] -= vet[i];
	}
	printf("%lld", ans[0]);
	for (int i=1; i<n; i++){
		ans[i] = 2*(vet[i-1] - (ans[i-1]/2));
		printf(" %lld", ans[i]);
	}
	printf("\n");
}