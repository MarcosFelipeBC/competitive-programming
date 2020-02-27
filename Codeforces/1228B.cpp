#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;

const int N = 1005;
int mat[N][N], r[N], c[N];

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i=0; i<n; i++){
		scanf("%d", &r[i]);
	}
	for (int i=0; i<m; i++){
		scanf("%d", &c[i]);
	}
	memset(mat, -1, sizeof mat);
	int qtd = 0;
	for (int i=0; i<n; i++){
		if(r[i] == 0) {
			mat[i][0] = 0;
		}
		for (int j=0; j<r[i]; j++){
			mat[i][j] = 1;
		}
		if(r[i] < m) mat[i][r[i]] = 0;
	}
	for (int j=0; j<m; j++){
		if(c[j] == 0){
			if(mat[0][j] == 1) {
				cout << 0 << endl;
				return 0;
			}
			else mat[0][j] = 0;
		}
		for (int i=0; i<c[j]; i++){
			if(mat[i][j] == 0){
				cout << 0 << endl;
				return 0;
			}
			mat[i][j] = 1;
		}
		if(c[j] < n){
			if(mat[c[j]][j] == 1) {
				cout << 0 << endl;
				return 0;
			}
			else mat[c[j]][j] = 0;
		} 
	}
	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			if(mat[i][j] == -1) qtd++;
		}
	}
	int ans = 1;
	for (int i=0; i<qtd; i++){
		ans = (ans * 2)%mod;
	}
	cout << ans << endl;
}