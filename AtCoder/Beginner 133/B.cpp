//https://atcoder.jp/contests/abc133/tasks/abc133_b

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 15;
const int MAXD = 15;

int point[MAXN][MAXD];

bool dist(int i, int j, const int& d){
	int ans = 0;
	for (int k=0; k<d; k++){
		ans += ((point[i][k] - point[j][k]) * (point[i][k] - point[j][k]));
	}
	return ((int)sqrt(ans) * (int)sqrt(ans) == ans);
}

int main()
{
	int n, d;
	scanf("%d %d", &n, &d);
	for (int i=0; i<n; i++){
		for (int j=0; j<d; j++)
			scanf("%d", &point[i][j]);
	}
	int ans = 0;
	for (int i=0; i<n; i++){
		for (int j=i+1; j<n; j++){
			if(dist(i, j, d)) ans++;
		}
	}
	printf("%d\n", ans);
}