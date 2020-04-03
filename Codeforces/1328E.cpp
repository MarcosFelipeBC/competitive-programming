#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
const int L = 20;
vector < int > g[N];
int ant[N][L], nv[N];

void build(int u, int p)
{
	ant[u][0] = p;
	for (int i=1; i<L; i++){
		ant[u][i] = ant[ant[u][i-1]][i-1];
	}
	for (int v : g[u]){
		if(v == p) continue ;
		nv[v] = nv[u]+1;
		build(v, u);
	}
}

int lca(int u, int v)
{
	if(nv[u] < nv[v]) swap(u, v);
	for (int i=L-1; i>=0; i--)
	{
		if(nv[u] - (1 << i) >= nv[v])
		{
			u = ant[u][i];
		}
	}
	if(u == v) return u;
	for (int i=L-1; i>=0; i--)
	{
		if(ant[u][i] != ant[v][i]){
			u = ant[u][i], v = ant[v][i];
		}
	}
	return ant[u][0];
}

bool onTheWay(const int &u, const int &v)
{
	int LCA = lca(u, v);
	if(LCA == u || LCA == v){
		return true;
	}
	return false;
}

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i=0; i<n-1; i++){
		int u, v;
		scanf("%d %d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	build(1, 1);
	while (m-- > 0)
	{
		int k;
		scanf("%d", &k);
		vector < int > query(k);
		int chosen = 1;
		for (int i=0; i<k; i++){
			scanf("%d", &query[i]);
			query[i] = ant[query[i]][0];
			if(nv[query[i]] > nv[chosen]) chosen = query[i];
		}
		bool ans = true;
		for (int i=0; i<k; i++){
			if(!onTheWay(chosen, query[i])) ans = false;
		}
		puts((ans) ? "YES" : "NO");
	}
}