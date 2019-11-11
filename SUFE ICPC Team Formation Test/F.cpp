#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;

const int N = 105;
const int M = 10005;
long long dp[N][M];
int vet[N];

int main(){
	int t;
	scanf("%d", &t);
	while (t-- > 0){
		memset(dp, 0LL, sizeof dp);
		int n, m;
		scanf("%d %d", &n, &m);
		for (int i=0; i<n; i++){
			scanf("%d", &vet[i]);
		}
		dp[0][0] = 1LL;
		for (int i=0; i<n; i++){
			for (int j=0; j<=m; j++){
				if(i > 0) dp[i][j] += dp[i-1][j];
				if(j - vet[i] >= 0) dp[i][j] += dp[i][j-vet[i]];
				dp[i][j] %= mod;
			}
		}
		printf("%lld\n", dp[n-1][m]);
	}
}
