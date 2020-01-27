#include <bits/stdc++.h>
using namespace std;

vector < vector < int > > mat;
map < int, int > mapa;

int solve(int pos, vector < int> &vet, int m)
{
	mapa.clear();
	int mx = -1;
	int n = vet.size();
	for (int i=0; i<n; i++){
		int x = vet[i];
		if((x-pos)%m == 0 && (x-pos)/m < n){
			int val;
			if(i >= (x-pos)/m) val = i - (x-pos)/m;
			else val = i + n - (x-pos)/m;
			mapa[val]++;
			if(mapa[val] > mapa[mx]) {
				mx = val;
			}
		}
	}
	int ans = n;
	for (int i=0; i<n; i++){
		ans = min(ans, n-mapa[i] + i);
	}
	return ans;
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	mat.resize(n, vector < int >(m));
	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			scanf("%d", &mat[i][j]);
		}
	}
	int ans = 0;
	for (int j=0; j<m; j++){
		vector < int > column;
		for (int i=0; i<n; i++){
			column.push_back(mat[i][j]);
		}
		ans += solve(j+1, column, m);
	}
	printf("%d\n", ans);
}