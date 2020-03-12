#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
int dp[N], dprev[N], vet[N];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i=0; i<n; i++){
		scanf("%d", &vet[i]);
	}
	int ans = 0;
	for (int i=1; i<n; i++){
		if(vet[i-1] < vet[i]) dp[i] = dp[i-1]+1;
		ans = max(ans, dp[i]+1);
	}
	for (int i=n-2; i>=0; i--){
		if(vet[i+1] > vet[i]) dprev[i] = dprev[i+1]+1;
		ans = max(ans, dprev[i]+1);
	}
	for (int i=1; i<n-1; i++){
		if(vet[i-1] < vet[i+1]){
			ans = max(ans, dp[i-1] + dprev[i+1]+2);
		}
	}
	printf("%d\n", ans);
}