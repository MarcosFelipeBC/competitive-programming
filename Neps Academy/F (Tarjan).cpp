//https://neps.academy/contest/215/problem/724

#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int low[N], d[N], vist[N], cnt = 0, root, ans = 0;
vector < int > g[N];

void dfs(int u, int p){
	vist[u] = 1;
	d[u] = low[u] = cnt++;
	for (int v : g[u]){
		if(!vist[v]){
			dfs(v, u);
			low[u] = min(low[u], low[v]);
		}
		else if(v != p) low[u] = min(low[u], d[v]);
	}
}

int solve(int u){
	vist[u] = 1;
	int mx1 = 0, mx2 = 0;
	for (int v : g[u]){
		if(!vist[v]){
			int sum = solve(v);
			if(low[v] > d[u]) sum++;
			if(sum >= mx1) {
				mx2 = mx1;
				mx1 = sum;
			}
			else if(sum > mx2) {
				mx2 = sum;
			}
		}
	}
	ans = max(ans, mx1 + mx2);
	return mx1;
}

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i=0; i<m; i++){
		int u, v;
		scanf("%d %d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for (int i=0; i<n; i++) if(g[i].size() >= 2) root = i;
	memset(vist, 0, sizeof vist);
	dfs(root, root);
	memset(vist, 0, sizeof vist);
	solve(root);
	printf("%d\n", ans);
}