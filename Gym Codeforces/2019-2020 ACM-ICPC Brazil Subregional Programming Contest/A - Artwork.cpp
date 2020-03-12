//https://codeforces.com/gym/102346/problem/A

#include <bits/stdc++.h>
using namespace std;

const int K = 1010;
int n, m;

typedef pair < int, pair < int, pair < int, int > > > quadra;
vector < int > g[K];
bitset < K > vist;

struct sensor {
	int x, y, r;
	bool a, b, c, d;
	sensor(){
		x = y = r = 0;
		a = b = c = d = false;
	}
	sensor(int _x, int _y, int _r){
		x = _x, y = _y, r = _r;
	}
	void build(){
		if(y - r <= 0) a = true;
		if(x + r >= n) b = true;
		if(y + r >= m) c = true;
		if(x - r <= 0) d = true;
	}
	int dist(sensor other) {
		return (x - other.x)*(x - other.x) + (y - other.y)*(y - other.y);
	}
	bool colide(sensor other) {
		return (dist(other) <= (r + other.r)*(r + other.r));
	}
}vet[K];

quadra dfs(int u){
	vist[u] = 1;
	quadra now = {vet[u].a, {vet[u].b, {vet[u].c, vet[u].d}}};
	for (int v : g[u]){
		if(vist[v]) continue ;
		quadra aux = dfs(v);
		now.first |= aux.first;
		now.second.first |= aux.second.first;
		now.second.second.first |= aux.second.second.first;
		now.second.second.second |= aux.second.second.second;
	}
	return now;
}

int main(){
	int k;
	scanf("%d %d %d", &n, &m, &k);
	for (int i=0; i<k; i++){
		int x, y, r;
		scanf("%d %d %d", &x, &y, &r);
		vet[i] = sensor(x, y, r);
		vet[i].build();
	}
	for (int i=0; i<k-1; i++){
		for (int j=i+1; j<k; j++){
			if(vet[i].colide(vet[j])){
				g[i].push_back(j);
				g[j].push_back(i);
			}
		}
	}
	bool ans = true;
	for (int i=0; i<k; i++){
		if(!vist[i]){
			quadra resp = dfs(i);
			if(resp.first && resp.second.second.second) ans = false;
			if(resp.first && resp.second.second.first) ans = false;
			if(resp.second.first && resp.second.second.first) ans = false;
			if(resp.second.first && resp.second.second.second) ans = false;
		}
	}
	puts((ans) ? "S" : "N");
}
