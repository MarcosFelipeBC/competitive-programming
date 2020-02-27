#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
long long dp[N], aux[N];
vector < int > vet[N];

int main(){
	int n, h;
	scanf("%d %d", &n, &h);
	for (int i=0; i<n; i++){
		for (int j=0; j<h; j++){
			int x;
			scanf("%d", &x);
			vet[i].push_back(x);
		}
	}
	for (int i=0; i<n; i++){
		dp[i] = vet[i][0];
	}
	for (int nv = 1; nv < h; nv++)
	{
		for (int i=0; i<n; i++){
			aux[i] = dp[i];
		}
		for (int i=0; i<n; i++){
			dp[i] = aux[i] + vet[i][nv];
			if(i) dp[i] = max(dp[i], aux[i-1]+vet[i][nv]);
			if(i+1 < n) dp[i] = max(dp[i], aux[i+1] + vet[i][nv]);
		}
	}
	long long mx = 0;
	for (int i=0; i<n; i++){
		mx = max(mx, dp[i]);
	}
	printf("%lld\n", mx);
}