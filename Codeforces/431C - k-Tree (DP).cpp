//https://codeforces.com/problemset/problem/431/C

#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;

typedef long long ll;

const int N = 105;

ll dp[N][2];

ll solve(int rem, int flag, const int &n, const int &d){
	if(rem < 0) return 0;
	if(rem == 0) return flag;
	ll &ans = dp[rem][flag];
	if(ans != -1) return ans;
	ans = 0LL;
	for (int i=1; i<=n; i++){
		ans = (ans%mod + solve(rem-i, (flag | (i >= d)), n, d)%mod)%mod;
	}
	return ans;
}

int main(){
	int n, k, d;
	scanf("%d %d %d", &n, &k, &d);
	memset(dp, -1, sizeof dp);
	printf("%lld\n", solve(n, 0, k, d));
}
