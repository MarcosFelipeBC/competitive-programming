#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;

typedef long long ll;
const int M = 15;
const int N = 1005;

ll dp[M][N][N];
int n, m;

ll solve(int pos, int lastA, int lastB){
	if(lastB < lastA) return 0LL;
	if(pos == m) return 1LL;
	ll &ans = dp[pos][lastA][lastB];
	if(ans != -1) return ans;
	ans = 0LL;
	ans = (ans + solve(pos, lastA+1, lastB))%mod;
	ans = (ans + solve(pos, lastA, lastB-1))%mod;
	ans = (ans - solve(pos, lastA+1, lastB-1) + mod)%mod;
	ans = (ans + solve(pos+1, lastA, lastB))%mod;
	return ans;
}
	
int main(){
	scanf("%d %d", &n, &m);
	memset(dp, -1, sizeof dp);
	printf("%lld\n", solve(0, 1, n)%mod);
}