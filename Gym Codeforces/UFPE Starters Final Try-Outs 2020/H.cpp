#include <bits/stdc++.h>
#define oo 0x3f3f3f3f3f3f3f3f
using namespace std;

const int N = 100005;
vector < pair < int, long long > > g[N];
long long dist[N], T[N];
priority_queue < pair < long long, int >, vector < pair < long long, int > >, greater < pair < long long, int > > > pq;

void dijkstra()
{
	while(!pq.empty())
	{
		int u = pq.top().second;
		long long d = pq.top().first;
		pq.pop();
		if(d > dist[u]) continue ;
		for (int i=0; i<g[u].size(); i++){
			int v = g[u][i].first;
			long long c = g[u][i].second;
			if(dist[v] > dist[u]+c)
			{
				dist[v] = dist[u]+c;
				pq.push({dist[v], v});
			}
		}
	}
	return ;
}

int main(){
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	for (int i=0; i<m; i++){
		int u, v;
		long long d;
		scanf("%d %d %lld", &u, &v, &d);
		g[u].push_back({v, d});
		g[v].push_back({u, d});
	}
	for (int i=1; i<=n; i++){
		scanf("%lld", &T[i]);
		for (int j=0; j<g[i].size(); j++){
			g[i][j].second += T[i];
		}
	}
	memset(dist, oo, sizeof dist);
	for (int i=0; i<k; i++){
		int x;
		scanf("%d", &x);
		dist[x] = 0LL;
		pq.push({0LL, x});
	}
	dijkstra();
	for (int i=1; i<=n; i++){
		dist[i] += T[i];
		printf("%lld\n", dist[i]);
	}
}