//https://codeforces.com/contest/1245/problem/D

#include <bits/stdc++.h>
using namespace std;

const int N = 2005;
typedef long long ll;
typedef pair < int, int > ii;

ii vet[N];
int c[N], k[N], p[N], hasStation[N], st[N];

ll cost(int u, int v){
	return (long long)(k[u] + k[v]) * (long long)(abs(vet[u].first - vet[v].first) + abs(vet[u].second - vet[v].second));
}

int find(int u){
	return p[u] = (u == p[u]) ? u : find(p[u]);
}

void join(int u, int v, long long &sum){
	u = find(u), v = find(v);
	if(c[st[u]] < c[st[v]]){
		sum -= c[st[v]];
		hasStation[st[v]] = 0;
		st[v] = st[u];
	}
	else {
		sum -= c[st[u]];
		hasStation[st[u]] = 0;
		st[u] = st[v];
	}
	p[v] = u;
}

int main(){
	int n;
	scanf("%d", &n);
	for (int i=1; i<=n; i++){
		scanf("%d %d", &vet[i].first, &vet[i].second);
	}
	for (int i=1; i<=n; i++){
		scanf("%d", &c[i]);
	}
	for (int i=1; i<=n; i++){
		scanf("%d", &k[i]);
	}
	
	vector < pair < ll, pair < int, int > > > edges;
	vector < pair < int, int > > ansEdges;
	
	for (int i=1; i<=n-1; i++){
		for (int j=i+1; j<=n; j++){
			edges.push_back({cost(i, j), {i, j}});
		}
	}
	
	ll sum = 0LL;
	for (int i=1; i<=n; i++) {
		p[i] = i;
		st[i] = i;
		hasStation[i] = 1;
		sum += c[i];
	}
	
	sort(edges.begin(), edges.end());
	int m = (int)edges.size();
	int qtd = n;
	long long money = 0LL;
	for (int i=0; i<m; i++){
		int u = edges[i].second.first, v = edges[i].second.second;
		ll val = edges[i].first;
		u = find(u), v = find(v);
		if(u != v){
			if(val <= max(c[st[u]], c[st[v]])){
				ansEdges.push_back({edges[i].second.first, edges[i].second.second});
				money += val;
				qtd--;
				join(u, v, sum);
			}
		}
	}
	money += sum;
	printf("%lld\n", money);
	printf("%d\n", qtd);
	for (int i=1; i<=n; i++){
		if(hasStation[i]) printf("%d ", i);
	}
	printf("\n%d\n", (int)ansEdges.size());
	for (int i=0; i<ansEdges.size(); i++){
		printf("%d %d\n", ansEdges[i].first, ansEdges[i].second);
	}
}
