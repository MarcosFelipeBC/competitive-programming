#include <bits/stdc++.h>
using namespace std;

int dp[5], vet[100005];
int main()
{
	int n;
	scanf("%d", &n);
	for (int i=0; i<n; i++) scanf("%d", &vet[i]);
	memset(dp, 0x3f3f3f3f, sizeof dp);
	dp[(n-1)%3] = 0;
	for (int i=n-2; i>=0; i--){
		dp[i%3] = 0x3f3f3f3f;
		if(i+2 < n) dp[i%3] = min(dp[i%3], dp[(i+2)%3] + abs(vet[i]-vet[i+2]));
		dp[i%3] = min(dp[i%3], dp[(i+1)%3] + abs(vet[i]-vet[i+1]));
	}
	printf("%d\n", dp[0]);
}