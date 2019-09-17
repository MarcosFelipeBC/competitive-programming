#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
int father[N], sz[N];
vector < int > g[N];
typedef pair < int, int > ii;
priority_queue < ii > pq;

void build(int u, int p){
	sz[u] = 1;
	for (int v : g[u]){
		if(v == p) continue ;
		build(v, u);
		sz[u] = max(sz[u], sz[v]+1);
	}
	return ;
}

void down(int u, int p){
	int mx = -1;
	for (int v : g[u]){
		if(v == p) continue ;
		if(mx == -1 || sz[v] > sz[mx]) mx = v;
	}
	for (int v : g[u]){
		if(v == p || v == mx) continue ;
		pq.push({sz[v], v});
	}
	if(mx != -1) down(mx, u);
}

int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i=2; i<=n; i++){
		int x;
		scanf("%d", &x);
		father[i] = x;
		g[i].push_back(x);
		g[x].push_back(i);
	}
	build(1, 1);
	pq.push({sz[1], 1});
	int ans = 0;
	while (k > 0 && !pq.empty()){
		int u = pq.top().second;
		int val = pq.top().first;
		pq.pop();
		ans += val;
		down(u, father[u]);
		k--;
	}
	printf("%d\n", ans);
}
