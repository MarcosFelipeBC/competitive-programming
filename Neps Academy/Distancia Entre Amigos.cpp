#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
int mx[N], vet[N];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i=0; i<n; i++){
		scanf("%d", &vet[i]);
	}
	mx[n-1] = vet[n-1] + n-1;
	for (int i=n-2; i>=0; i--){
		mx[i] = mx[i+1];
		mx[i] = max(mx[i], vet[i] + i);
	}
	int ans = 0;
	for (int i=0; i<n-1; i++){
		ans = max(ans, vet[i] + mx[i+1] - i);
	}
	printf("%d\n", ans);
}