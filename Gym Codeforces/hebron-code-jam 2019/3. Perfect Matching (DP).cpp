//https://codeforces.com/gym/102157/problem/3

#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;

typedef long long ll;
const int N = 2020;

ll dp[N][(1 << 10)];
int block[N][N];

ll solve(int pos, int mask, const int &n, const int &e){
	if(mask & (1 << 9)) mask ^= (1 << 9);
	if(pos == n) return 1;
	ll &ans = dp[pos][mask];
	if(ans != -1) return ans;
	int p = pos;
	ans = 0LL;
	for (int i=4; i<9; i++, p--){
		if(p >= 0 && abs(p-pos) <= e && !block[pos][p] && !(mask & (1 << i))){
			ans = (ans + solve(pos+1, (mask | (1 << i)) << 1, n, e))%mod;
		}
	}
	p = pos+1;
	for (int i=3; i>=0; i--, p++){
		if(p < n && abs(p-pos) <= e && !block[pos][p] && !(mask & (1 << i))){
			ans = (ans + solve(pos+1, (mask | (1 << i)) << 1, n, e))%mod;
		}
	}
	return ans;
}

int main(){
	int n, e, k;
	scanf("%d %d %d", &n, &e, &k);
	for (int i=0; i<k; i++){
		int u, v;
		scanf("%d %d", &u, &v);
		u--, v--;
		block[u][v] = 1;
	}
	memset(dp, -1, sizeof dp);
	printf("%lld\n", solve(0, 0, n, e));
}
