//https://www.spoj.com/problems/ABA12C/

#include <bits/stdc++.h>
#define oo 0x3f3f3f3f
using namespace std;

const int N = 105;
int dp[N][N], vet[N], k;

int solve(int n, int kg){
	if(kg == 0) return 0;
	if(n <= 0 || kg < 0) return oo;
	int &ans = dp[n][kg];
	if(ans != -1) return ans;
	ans = oo;
	for (int i=1; i<=k; i++){
		if(vet[i] == -1) continue ;
		ans = min(ans, solve(n-1, kg-i) + vet[i]);
	}
	return ans;
}

int main(){
	int t;
	scanf("%d", &t);
	while (t-- > 0){
		int n;
		scanf("%d %d", &n, &k);
		for (int i=1; i<=k; i++) scanf("%d", &vet[i]);
		memset(dp, -1, sizeof dp);
		int ans = solve(n, k);
		if(ans == oo) ans = -1;
		printf("%d\n", ans);
	}
}
