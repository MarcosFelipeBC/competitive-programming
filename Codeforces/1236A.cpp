#include <bits/stdc++.h>
using namespace std;

const int N = 105;

int dp[N][N][N];

int solve(int a, int b, int c){
	if(a < 0 || b < 0 || c < 0) return -4;
	int &ans = dp[a][b][c];
	if(ans != -1) return ans;
	ans = 0;
	ans = max(ans, max(solve(a-1, b-2, c), solve(a, b-1, c-2)) + 3);
	return ans;
}

int main(){
	int t;
	scanf("%d", &t);
	while (t-- > 0){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		memset(dp, -1, sizeof dp);
		printf("%d\n", solve(a, b, c));
	}
}