//https://codeforces.com/gym/102157/problem/2

#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
int mat[N][N], vist[N][N];

int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
int contCol, contLine;
bitset < N > vistCol, vistLine;

void explore(int x, int y, const int &p, const int &n, const int &m){
	if(vistCol[y] == 0) contCol--;
	vistCol[y] = 1;
	if(vistLine[x] == 0) contLine--;
	vistLine[x] = 1;
	vist[x][y] = 1;
	for (int i=0; i<4; i++){
		int a = ((x + dx[i]) + n)%n, b = ((y + dy[i]) + m)%m;
		if(!vist[a][b] && mat[a][b] >= p) explore(a, b, p, n, m);
	}
}

int main(){
	int n, m;
	double auxp;
	scanf("%d %d", &n, &m);
	char str[5], aux[3];
	scanf("%s", str);
	aux[0] = str[2], aux[1] = str[3], aux[2] = '\0';		
	int p = atoi(aux);
	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			scanf("%s", str);
			aux[0] = str[2], aux[1] = str[3], aux[2] = '\0';		
			mat[i][j] = atoi(aux);
		}
	}
	bool ans = false;
	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			if(!vist[i][j] && mat[i][j] >= p) {
				vistCol.reset(), vistLine.reset();
				contCol = m, contLine = n;
				explore(i, j, p, n, m);
				if(contCol + contLine == 0) ans = true;
			}
		}
	}
	puts((ans) ? "YES" : "NO");
}
