//https://codeforces.com/gym/101810/problem/M

#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
const int L = 18;
int path[N], pathRev[N], ant[N][L], nv[N];
vector < pair < int, pair < int, int > > > g[N];

void dfs(int u, int p){
	ant[u][0] = p;
	for (int i=1; i<L; i++) ant[u][i] = ant[ant[u][i-1]][i-1];
	for (pair < int, pair < int, int > > v : g[u]){
		if(v.first == p) continue ;
		path[v.first] = path[u] + v.second.first;
		pathRev[v.first] = pathRev[u] + v.second.second;
		nv[v.first] = nv[u]+1;
		dfs(v.first, u);
	}
}

int lca(int u, int v){
	if(nv[u] < nv[v]) swap(u, v);
	for (int i=L-1; i>=0; i--){
		if(nv[u] - (1 << i) >= nv[v]) u = ant[u][i];
	}
	if(u == v) return u;
	for (int i=L-1; i>=0; i--){
		if(ant[u][i] != ant[v][i]){
			u = ant[u][i], v = ant[v][i];
		}
	}
	return ant[u][0];
}

int main(){
	int t;
	scanf("%d", &t);
	while (t-- > 0){
		int n;
		scanf("%d", &n);
		int sum = 0;
		for (int i=0; i<n-1; i++){
			int u, v, c, rc;
			scanf("%d %d %d %d", &u, &v, &c, &rc);
			g[u].push_back({v, {c, rc}});
			g[v].push_back({u, {rc, c}});
			sum += c;
			sum += rc;
		}
		path[1] = pathRev[1] = 0;
		nv[1] = 0;
		dfs(1, 1);
		int q;
		scanf("%d", &q);
		while (q--){
			int x, y;
			scanf("%d %d", &x, &y);
			int LCA = lca(x, y);
			printf("%d\n", sum - (path[x] - path[LCA] + pathRev[y] - pathRev[LCA]));
		}
		for (int i=1; i<=n; i++) g[i].clear();
	}
}
