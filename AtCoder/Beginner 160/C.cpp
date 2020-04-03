//https://atcoder.jp/contests/abc160/tasks/abc160_c

#include <bits/stdc++.h>
using namespace std;

const int N = 400005;
int vet[N];

int main()
{
	int k, n;
	scanf("%d %d", &k, &n);
	for (int i=0; i<n; i++){
		scanf("%d", &vet[i]);
	}
	for (int i=n; i<2*n; i++){
		vet[i] = vet[i-n] + k;
	}
	int ans = 1000000000;
	for (int i=n-1; i<2*n-1; i++){
		ans = min(ans, (vet[i] - vet[i-n+1]));
	}
	printf("%d\n", ans);
}