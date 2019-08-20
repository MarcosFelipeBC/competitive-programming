//https://www.spoj.com/problems/MTOTALF/
#include <bits/stdc++.h>
using namespace std;

const int N = 105;
const int M = 1005;

int cur = 0, tempo, vist[N];

struct ed {
	int to, f, c;
	ed(){
		to = f = c = 0;
	}
	ed(int x, int y, int z){
		to = x, f = y, c = z;
	}
}edges[2*M]; //double to the residual graph

vector < int > g[N];

void add_edge(int u, int v, int c, int rc){
	edges[cur] = ed(v, 0, c);
	g[u].push_back(cur++);
	edges[cur] = ed(u, 0, rc);
	g[v].push_back(cur++);
}

int dfs(int u, int dest, int f){
	if(u == dest) return f;
	vist[u] = tempo;
	for (int e : g[u]){
		int v = edges[e].to, cap = edges[e].c - edges[e].f;
		if(vist[v] < tempo && cap > 0) {
			if(int a = dfs(v, dest, min(f, cap))){
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

int convert(char c){
	if(c <= 'Z') return c-'A';
	else return c-'a' + 26;
}

int main(){
	int m;
	cin >> m;
	for (int i=0; i<m; i++){
		char u, v;
		int c;
		cin >> u >> v >> c;
		
		add_edge(convert(u), convert(v), c, 0);
	}
	cout << mf(convert('A'), convert('Z')) << endl;
}
