#include <bits/stdc++.h>


const int N = 100007, inf = 0x3f3f3f3f;

using namespace std;

vector<int> g[N];

int lev[N], vis[N][2], pai[N][22];
int cnt[N];

typedef pair<int, int> ii;
int tt;
void dfs(int u, int p = -1, int l = 0) {
	if(p == -1) p = u;
	pai[u][0] = p;
	for(int i = 1; i < 22; ++i) {
		pai[u][i] = pai[pai[u][i-1]][i-1];
	}

	vis[u][0] = ++tt;
	for(int v : g[u]) {
		if(v == p) continue;
		dfs(v, u, l+1);
		cnt[u] += cnt[v];
	}

	cnt[u] = max(cnt[u], 1);
	vis[u][1] = tt;
}

int lca(int u, int v) {
	if(u == v) return u;

	if(vis[u][0] > vis[v][0]) swap(u, v);

	for(int i = 21; i >= 0; --i) {
		int w = pai[v][i];
		if(vis[w][0] > vis[u][0]) v = w;
	}

	return pai[v][0];
}

int group[N];
int head[N];
set<ii> caras[N];

int main() {
	freopen("gangsters.in", "r", stdin);
	freopen("gangsters.out", "w", stdout);
	int n, q;
	cin >> n >> q;
	for (int i=2; i<=n; i++){
		int x;
		cin >> x;
		g[i].push_back(x);
		g[x].push_back(i);
	}

	dfs(1);

	for(int i = 0; i < g[1].size(); ++i) {
		int v = g[1][i];
		int l = vis[v][0], r = vis[v][1];
		for(int j = l; j <= r; ++j) group[j] = i;
	}

	int clogs = 0;
	int people = 0;

	while (q--){
		char c;
		int v;
		cin >> c >> v;
		int gr = group[vis[v][0]];

		
		if(c == '+'){
			if(head[gr]) people -= cnt[head[gr]] - caras[gr].size();
			else clogs ++;

			caras[gr].insert(ii(vis[v][0], v));
			int u = caras[gr].begin()->second;
			int v = caras[gr].rbegin()->second;
			head[gr] = lca(u, v);
			
			people += cnt[head[gr]] - caras[gr].size();
		}
		else {

			if(head[gr]) people -= cnt[head[gr]] - caras[gr].size();

			caras[gr].erase(ii(vis[v][0], v));

			if(caras[gr].size() == 0) {
				head[gr] = 0;
				clogs--;
			} else {
				int u = caras[gr].begin()->second;
				int v = caras[gr].rbegin()->second;
				head[gr] = lca(u, v);
				people += cnt[head[gr]] - caras[gr].size();
			}
		}




		printf("%d %d\n", clogs, people);
	}
}