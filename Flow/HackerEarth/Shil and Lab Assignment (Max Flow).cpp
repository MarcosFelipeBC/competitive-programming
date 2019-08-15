//https://www.hackerearth.com/pt-br/practice/algorithms/graphs/maximum-flow/practice-problems/algorithm/shil-and-lab-assignment-14/
#include <bits/stdc++.h>
using namespace std;

const int N = 301015;
const int M = 500000;

int cur = 0, tempo, vist[N];
vector < int > g[N];

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
		if(cap > 0 && vist[v] < tempo) {
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
	tempo = 1;
	while (int a = dfs(s, t, INT_MAX)){
		flow += a;
		tempo++;
	}
	return flow;
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	int s = 0, t = 301010;
	for (int i=1; i<=m; i++) add_edge(s, i, 1, 0);
	for (int i=0; i<n; i++){
		int val;
		scanf("%d", &val);
		add_edge(val+m, t, 1, 0);
		for (int x = 1; x*x <= val; x++){
			if(val%x == 0) {
				if(x <= m) add_edge(x, m+val, INT_MAX, 0);
				if(val/x <= m) add_edge(val/x, m+val, INT_MAX, 0);
			}
		}
	}
	printf("%d\n", mf(s, t));
}
