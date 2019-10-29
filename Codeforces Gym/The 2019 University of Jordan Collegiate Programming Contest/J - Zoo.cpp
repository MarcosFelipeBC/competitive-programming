//https://codeforces.com/gym/102267/problem/J

#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;

typedef long long ll;
const int N = 100005;
const int M = 2005;

ll dp[M][M];
int k;

ll back(int desl, int passo){
	if(desl == -1 || desl > k) return 0;
	if(passo == 0) return (desl == 0);
	ll &ans = dp[desl][passo];
	if(ans != -1) return ans;
	return ans = (back(desl-1, passo-1) + back(desl+1, passo-1) + (desl == 0))%mod;
}

int main(){
	int n, m;
	scanf("%d %d %d", &n, &k, &m);
	memset(dp, -1, sizeof dp);
	ll ans = back(1, m-1);
	printf("%d\n", (2LL*n*ans)%mod);
}
