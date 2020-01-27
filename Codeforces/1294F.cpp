#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
vector < int > g[N];
int dist[N], vtx, mx, ans;
vector < int > vet;

void dfs(int u, int d){
	dist[u] = d;
	if(dist[u] > mx) {
		mx = dist[u];
		vtx = u;
	}
	for (int v : g[u]){
		if(dist[v] == -1){
			dfs(v, d+1);
		}
	}
}

bool reach(int u, int dest){
	if(dest == u) return true;
	dist[u] = 1;
	for (int v: g[u]){
		if(dist[v] == -1){
			if(reach(v, dest)){
				ans++;
				vet.push_back(v);
				return true;
			}
		}
	}
	return false;
}

void bfs(){
	memset(dist, -1, sizeof dist);
	queue < int > q;
	for (int x : vet){
		dist[x] = 0;
		q.push(x);
		vtx = x;
	}
	while (!q.empty()){
		int u = q.front();
		q.pop();
		if(dist[u] > mx){
			mx = dist[u];
			vtx = u;
		}
		for (int v : g[u]){
			if(dist[v] == -1){
				q.push(v);
				dist[v] = dist[u]+1;
			}
		}
	}
	ans += dist[vtx];
}

int main(){
	int n;
	scanf("%d", &n);
	for (int i=0; i<n-1; i++){
		int u, v;
		scanf("%d %d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	memset(dist, -1, sizeof dist);
	mx = 0;
	dfs(1, 0);
	int first = vtx;
	memset(dist, -1, sizeof dist);
	mx = 0;
	dfs(first, 0);
	int second = vtx;
	memset(dist, -1, sizeof dist);
	vet.push_back(first);
	reach(first, second);
	ans = vet.size()-1;
	mx = 0;
	bfs();
	int third = vtx;
	printf("%d\n%d %d %d\n", ans, first, second, third);

}