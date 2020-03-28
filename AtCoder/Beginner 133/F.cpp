//https://atcoder.jp/contests/abc133/tasks/abc133_f

#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
const int L = 18;

vector < pair < int, pair < int, int > > > g[N];
vector < pair < int, pair < int, pair < int, int > > > > queries[N];
int ant[N][L], nv[N], ans[N], dist[N];
vector < int > rememberList[N];
map < int, int > remember[2][N];
map < int, int > now[2];

void build(int u, int p)
{
	ant[u][0] = p;
	for (int i=1; i<L; i++){
		ant[u][i] = ant[ant[u][i-1]][i-1];
	}
	for (pair < int, pair < int, int > > v : g[u])
	{
		if(v.first == p) continue ;
		nv[v.first] = nv[u]+1;
		dist[v.first] = dist[u] + v.second.second;
		build(v.first, u);
	}
}

int lca(int u, int v)
{
	if(nv[u] < nv[v]) swap(u, v);
	for (int i=L-1; i>=0; i--)
	{
		if(nv[ant[u][i]] >= nv[v]){
			u = ant[u][i];
		}
	}
	if(u == v) return u;
	for (int i=L-1; i>=0; i--)
	{
		if(ant[u][i] != ant[v][i])
		{
			u = ant[u][i], v = ant[v][i];
		}
	}
	return ant[v][0];
}

void solve(int u, int p)
{
	for (int x : rememberList[u])
	{
		remember[0][u][x] = now[0][x];
		remember[1][u][x] = now[1][x];
	}

	for (auto x : queries[u]){
		int LCA = x.first;
		int id = x.second.second.second;
		ans[id] -= (now[1][x.second.first] - remember[1][LCA][x.second.first]);
		ans[id] += ((now[0][x.second.first] - remember[0][LCA][x.second.first]) * x.second.second.first);
	}

	for (pair < int, 	pair < int, int > > v : g[u])
	{
		if(v.first == p) continue ;
		now[0][v.second.first]++;
		now[1][v.second.first] += v.second.second;
		solve(v.first, u);
		now[0][v.second.first]--;
		now[1][v.second.first] -= v.second.second;
	}
}

int main()
{
	int n, q;
	scanf("%d %d", &n, &q);
	for (int i=0; i<n-1; i++){
		int u, v, c, d;
		scanf("%d %d %d %d", &u, &v, &c, &d);
		g[u].push_back({v, {c, d}});
		g[v].push_back({u, {c, d}});
	}
	nv[1] = 0;
	build(1, 1);
	for (int i=0; i<q; i++){
		int x, y, u, v;
		scanf("%d %d %d %d", &x, &y, &u, &v);
		int LCA = lca(u, v);
		rememberList[LCA].push_back(x);
		queries[u].push_back({LCA, {x, {y, i}}});
		queries[v].push_back({LCA, {x, {y, i}}});
		ans[i] = dist[u] + dist[v] - 2*dist[LCA];
	}
	solve(1, 1);
	for (int i=0; i<q; i++)
	{
		printf("%d\n", ans[i]);
	}
}
