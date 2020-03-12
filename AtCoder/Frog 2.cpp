#include <bits/stdc++.h>
#define oo 0x3f3f3f3f
using namespace std;

const int N = 100005;
const int K = 105;

int dp[K];
int vet[N];

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i=0; i<n; i++)
	{
		scanf("%d", &vet[i]);
	}
	dp[(n-1)%(k+1)] = 0;
	for (int i=n-2; i>=0; i--)
	{
		dp[i%(k+1)] = oo;
		for (int j=i+1; j<min(n, i+k+1); j++){
			dp[i%(k+1)] = min(dp[i%(k+1)], dp[j%(k+1)] + abs(vet[i] - vet[j]));
		}
	}
	printf("%d\n", dp[0]);
}