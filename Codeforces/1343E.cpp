#include <bits/stdc++.h>
#define oo 0x3f3f3f3f3f3f3f3f
using namespace std;

const int N = 200005;
vector < int > g[N];
int dist[3][N];
long long p[3*N];

void bfs(int idx, const vector < int >& abc){
	int start = abc[idx];
	dist[idx][start] = 0;
	queue < int > q;
	q.push(start);
	while (!q.empty()){
		int u = q.front();
		q.pop();
		for (int v : g[u]){
			if(dist[idx][v] == -1) {
				dist[idx][v] = dist[idx][u] + 1;
				q.push(v);
			}
		}
	}
}

long long solve(const vector < int >& abc, const int& n, const int& m){

	bfs(0, abc);
	bfs(1, abc);
	bfs(2, abc);

	for (int i=1; i<m; i++){
		p[i] += p[i-1];
	}
	for (int i=m; i<3*m; i++) p[i] = oo;

	int a = abc[0], b = abc[1], c = abc[2];
	long long ans = oo;
	for (int i=1; i<=n; i++){
		int qtd1 = dist[0][i];
		int qtd2 = dist[2][i];
		int qtd3 = dist[1][i];
		ans = min(ans, ((qtd1+qtd2+qtd3-1 >= 0) ? p[qtd1+qtd2+qtd3-1] : 0 ) + ((qtd3-1 >= 0) ? p[qtd3-1] : 0));
	}
	return ans;
}

int main()
{
	int t;
	scanf("%d", &t);
	while (t-- > 0)
	{
		int n, m, a, b, c;
		scanf("%d %d %d %d %d", &n, &m, &a, &b, &c);
		for (int i=1; i<=n; i++) dist[0][i] = dist[1][i] = dist[2][i] = -1, g[i].clear();
		vector < int > abc = {a, b, c};
		for (int i=0; i<m; i++) scanf("%lld", &p[i]);
		sort(p, p+m);
		for (int i=0; i<m; i++){
			int u, v;
			scanf("%d %d", &u, &v);
			g[u].push_back(v);
			g[v].push_back(u);
		}
		printf("%lld\n", solve(abc, n, m));
	}
}