//https://codeforces.com/contest/1213/problem/G

#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
int p[N];
long long ans[N], sz[N];

int find(int x){
	return p[x] = (x == p[x]) ? x : find(p[x]);
}

void une(int x, int y, long long &resp){
	x = find(x), y = find(y);
	p[y] = x;
	resp += (sz[x] * sz[y]);
	sz[x] += sz[y];
	sz[y] = 0;
}

int main(){
	int n, q;
	scanf("%d %d", &n, &q);
	vector < pair < int, pair < int, int > > > edges;
	for (int i=0; i<n-1; i++){
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		edges.push_back({w, {u, v}});
	}
	sort(edges.begin(), edges.end());
	vector < pair < int, int > > queries;
	for (int i=0; i<q; i++){
		int w;
		scanf("%d", &w);
		queries.push_back({w, i});
	}
	sort(queries.begin(), queries.end());
	for (int i=1; i<=n; i++) p[i] = i, sz[i] = 1;
	long long resp = 0LL;
	int idx = 0;
	
	for (int i=0; i<q; i++){
		while (idx < n-1 && edges[idx].first <= queries[i].first){
			int u = edges[idx].second.first, v = edges[idx].second.second;
			if(find(u) != find(v)){
				une(u, v, resp);
			}
			idx++;
		}
		ans[queries[i].second] = resp;
	}
	
	for (int i=0; i<q; i++){
		if(i) printf(" ");
		printf("%lld", ans[i]);
	}
	puts("");
}
