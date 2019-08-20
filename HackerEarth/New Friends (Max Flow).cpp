//https://www.hackerearth.com/pt-br/practice/algorithms/graphs/maximum-flow/practice-problems/algorithm/new-friends/description/
#include <bits/stdc++.h>
using namespace std;

const int N = 155;
const int M = 10005;
vector < int > g[N];
int tempo, cur, vist[N];

struct ed {
	int to, f, c;
	ed(){
		to = f = c = 0;
	}
	ed(int _to, int _f, int _c){
		to = _to, f = _f, c = _c;
	}
}edges[2*M];

void add_edge(int u, int v, int c, int rc){
	edges[cur] = ed(v, 0, c);
	g[u].push_back(cur++);
	edges[cur] = ed(u, 0, rc);
	g[v].push_back(cur++);
}

int dfs(int u, int t, int mn){
	if(u == t) return mn;
	vist[u] = tempo;
	for (int e : g[u]){
		int v = edges[e].to, cap = edges[e].c - edges[e].f;
		if(cap > 0 && vist[v] < tempo){
			if(int a = dfs(v, t, min(mn, cap))){
				edges[e].f += a;
				edges[e^1].f -= a;
				return a;
			}
		}	
	}
	return 0;
}

int mf(int s, int t){
	int flow = 0;
	while (int a = dfs(s, t, INT_MAX)){
		flow += a;
		tempo++;
	}
	return flow;
}

int main(){
	int t;
	scanf("%d", &t);
	tempo = 1;
	while (t-- > 0){
		int n, r;
		scanf("%d %d", &n, &r);
		cur = 0;
		for (int i=1; i<=n; i++) g[i].clear();
		for (int i=0; i<r; i++){
			int u, v;
			scanf("%d %d", &u, &v);
			add_edge(u, v, 1, 0);
		}
		int a, b, k;
		scanf("%d %d %d", &a, &b, &k);
		puts((mf(a, b) >= k+1) ? "YES" : "NO");
	}
}
