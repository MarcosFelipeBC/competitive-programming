#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;

const int N = 100005;
int vet[N];

int main()
{
	int t;
	scanf("%d", &t);
	while (t-- > 0)
	{
		int n;
		scanf("%d", &n);
		for (int i=0; i<n; i++){
			scanf("%d", &vet[i]);
		}
		sort(vet, vet+n, greater < int >());
		long long ans = 0LL;
		for (int i=0; i<n; i++){
			ans = (ans + max(0, vet[i]-i))%mod;
		}
		printf("%lld\n", ans);
	}
}