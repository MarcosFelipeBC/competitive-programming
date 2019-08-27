//Edmonds-Karp algorithm to solve maximum flow problems
//Complexity - O(V*(E^2))

#include <bits/stdc++.h>
#define oo 0x3f3f3f3f
using namespace std;

const int N = 105;
const int M = 1005;

vector < int > g[N];
int p[N], vist[N], tempo, cur = 0;

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
	q.push({s, INT_MAX}); //store the vertex and the minimum capacity in the path
	vist[s] = tempo;
	p[s] = -1;
	int f = 0;
	while (!q.empty()){
		int u = q.front().first;
		int flow = q.front().second;
		if(u == t) {
			f = flow; //here I already have the minimum capacity
			break;
		}
		q.pop();
		for (int e : g[u]){
			int v = edges[e].to, cap = edges[e].c - edges[e].f;
			if(cap > 0 && vist[v] < tempo) {
				vist[v] = tempo;
				p[v] = e;
				q.push({v, min(flow, cap)});
			}
		}
	}
	if(f != 0){
		int v = t;
		while (p[v] != -1){
			int e = p[v];
			edges[e].f += f;
			edges[e^1].f -= f;
			v = edges[e].from;
		}
	}
	return f;
}

int mf(int s, int t){
	int flow = 0;
	tempo = 1;
	while (int a = bfs(s, t)){
		tempo++;
		flow += a;
	}
	return flow;
}

int main(){
	
}
