#include <bits/stdc++.h>
#define oo 0x3f3f3f3f
using namespace std;

const int N = 303;
int dist[N][N];

int main(){
	int n, m, l;
	scanf("%d %d %d", &n, &m, &l);
	memset(dist, oo, sizeof dist);
	for (int i=0; i<m; i++){
		int u, v, c;
		scanf("%d %d %d", &u, &v, &c);
		dist[u][v] = c;
		dist[v][u] = c;
	}
	for (int k=1; k<=n; k++){
		for (int i=1; i<=n; i++){
			for (int j=1; j<=n; j++){
				if(i != j) dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	for (int i=1; i<=n; i++){
		for (int j=1; j<=n; j++){
			if(i != j) {
				if(dist[i][j] <= l) dist[i][j] = 1;
				else dist[i][j] = oo;
			}
		}
	}
	
	for (int k=1; k<=n; k++){
		for (int i=1; i<=n; i++){
			for (int j=1; j<=n; j++){
				if(dist[i][k] == -1 || dist[k][j] == -1) continue ;
				if(i != j) dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	int q;
	scanf("%d", &q);
	while (q-- > 0){
		int u, v;
		scanf("%d %d", &u, &v);
		printf("%d\n", ((dist[u][v] != oo) ? dist[u][v]-1 : -1));
	}
}
