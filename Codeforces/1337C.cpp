#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
vector < int > g[N];
vector < int > resp;

int dfs(int u, int p, int qtd)
{
	int children = 0;
	for (int v : g[u]){
		if(v == p) continue ;
		children += (1 + dfs(v, u, qtd+1));
	}
	resp.push_back(qtd - children);
	return children;
}

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i=0; i<n-1; i++)
	{
		int u, v;
		scanf("%d %d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1, 1, 0);
	sort(resp.begin(), resp.end(), greater < int >());
	long long ans = 0LL;
	for (int i=0; i<k; i++) {
		ans += resp[i];
	}
	printf("%lld\n", ans);
}