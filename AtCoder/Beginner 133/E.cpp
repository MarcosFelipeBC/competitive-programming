//https://atcoder.jp/contests/abc133/tasks/abc133_e

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod =  1000000007;
const int N = 100005;

vector < int > g[N];
ll fat[N];

ll fastPow(ll base, ll p)
{
	if(p == 0) return 1LL;
	ll x = fastPow(base, p >> 1);
	x = (x * x)%mod;
	if(p & 1) x = (x * base)%mod;
	return x;
}	

ll dfs(int u, int p, const int k)
{
	ll ans = 1LL;
	int rem = k - (p != -1) - 1;
	int children = g[u].size() - (p != -1);

	if(rem < children) return 0LL;
	ans = (ans * (fat[rem] * fastPow(fat[rem-children], mod-2))%mod)%mod;

	for (int v : g[u])
	{
		if(v == p) continue ;
		ans = (ans * dfs(v, u, k))%mod;
	}

	return ans;
}

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	fat[0] = 1LL;
	for (int i=1; i<=k; i++){
		fat[i] = (fat[i-1] * i)%mod;
	}
	for (int i=0; i<n-1; i++){
		int u, v;
		scanf("%d %d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	ll ans = (k * dfs(1, -1, k))%mod;
	printf("%lld\n", ans);
}