//https://codeforces.com/gym/102346/problem/I

#include <bits/stdc++.h>
#define oo 0x3f3f3f3f
using namespace std;

const int N = 404;
pair < int, int > t[N];
int distMin[N][N][N], distMax[N][N][N];

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i=1; i<=n; i++){
		scanf("%d", &t[i].first);
		t[i].second = i;
	}
	sort(t+1, t+n+1);
	memset(distMin, oo, sizeof distMin);
	memset(distMax, oo, sizeof distMax);
	for (int i=0; i<m; i++){
		int u, v, d;
		scanf("%d %d %d", &u, &v, &d);
		distMin[1][u][v] = min(distMin[1][u][v], d);
		distMin[1][v][u] = distMin[1][u][v];
		distMax[1][u][v] = distMax[1][v][u] = distMin[1][u][v];
	}
	int k = 1;
	for (int cnt=1; cnt<=n; cnt++){
		if(cnt != 1 && t[cnt-1].first != t[cnt].first) k++;
		int u = t[cnt].second;
		for (int i=1; i<=n; i++){
			for (int j=1; j<=n; j++){
				distMin[k][i][j] = min(distMin[k][i][j], distMin[k][i][u] + distMin[k][u][j]);
				distMin[k+1][i][j] = distMin[k][i][j];
			}
		}
	}
	for (int cnt = k+1; cnt <= n; cnt++){
		for (int i=1; i<=n; i++){
			for (int j=1; j<=n; j++){
				distMin[cnt][i][j] = distMin[cnt-1][i][j];
			}
		}
	}
	sort(t+1, t+n+1, greater < pair < int, int > >());
	k = 1;
	for (int cnt=1; cnt<=n; cnt++){
		if(cnt != 1 && t[cnt-1].first != t[cnt].first) k++;
		int u = t[cnt].second;
		for (int i=1; i<=n; i++){
			for (int j=1; j<=n; j++){
				distMax[k][i][j] = min(distMax[k][i][j], distMax[k][i][u] + distMax[k][u][j]);
				distMax[k+1][i][j] = distMax[k][i][j];
			}
		}
	}
	for (int cnt = k+1; cnt <= n; cnt++){
		for (int i=1; i<=n; i++){
			for (int j=1; j<=n; j++){
				distMax[cnt][i][j] = distMax[cnt-1][i][j];
			}
		}
	}
	int q;
	scanf("%d", &q);
	while (q-- > 0){
		int u, v, k, op;
		scanf("%d %d %d %d", &u, &v, &k, &op);
		if(op == 0) {
			printf("%d\n", (distMin[k][u][v] != oo) ? distMin[k][u][v] : -1);
		}
		else {
			printf("%d\n", (distMax[k][u][v] != oo) ? distMax[k][u][v] : -1);
		}
	}
}
