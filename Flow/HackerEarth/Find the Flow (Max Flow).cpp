//https://www.hackerearth.com/pt-br/practice/algorithms/graphs/maximum-flow/practice-problems/algorithm/find-the-flow/
#include <bits/stdc++.h>
using namespace std;

const int N = 30;
const int M = 55;

int cur = 0, tempo, vist[N], p[N];
vector < int > g[N];

struct ed {
	int from, to, f, c;
	ed(){
		from = to = f = c = 0;
	}
	ed(int _from, int _to, int _f, int _c){
		from = _from, to = _to, f = _f, c = _c;
	}
}edges[2*M];

void add_edge(int u, int v, int c, int rc){
	edges[cur] = ed(u, v, 0, c);
	g[u].push_back(cur++);
	edges[cur] = ed(v, u, 0, rc);
	g[v].push_back(cur++);
}

int bfs(int s, int t){
	queue < pair < int, int > > q;
	q.push({s, INT_MAX});
	vist[s] = tempo;
	p[s] = -1;
	int f = 0;
	while (!q.empty()){
		int u = q.front().first;
		int flow = q.front().second;
		q.pop();
		if(u == t) {
			f = flow;
			break;
		}
		for (int e : g[u]){
			int v = edges[e].to, cap = edges[e].c - edges[e].f;
			if(vist[v] < tempo && cap > 0){
				p[v] = e;
				vist[v] = tempo;
				q.push({v, min(flow, cap)});
			}
		}
	}
	int v = t;
	while (p[v] != -1){
		int e = p[v];
		edges[e].f += f;
		edges[e^1].f -= f;
		v = edges[e].from;
	}
	return f;
}

int mf(int s, int t){
	int flow = 0;
	tempo = 1;
	while (int a = bfs(s, t)){
		flow += a;
		tempo++;
	}
	return flow;
}

int main(){
	int m;
	cin >> m;
	for (int i=0; i<m; i++){
		char u, v;
		int c;
		cin >> u >> v >> c;
		add_edge(u-'A'+1, v-'A'+1, c, 0);
	}
	cout << mf('S'-'A'+1, 'T'-'A'+1) << endl;
}
