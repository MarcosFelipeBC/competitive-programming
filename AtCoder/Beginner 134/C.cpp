#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
int dp[N], vet[N];

int main(){
	int n;
	scanf("%d", &n);
	for (int i=0; i<n; i++){
		scanf("%d", &vet[i]);
	}
	int mx = -1;
	for (int i=n-2; i>=0; i--){
		dp[i] = max(vet[i+1], dp[i+1]);
	}
	for (int i=0; i<n; i++){
		printf("%d\n", max(mx, dp[i]));
		mx = max(vet[i], mx);
	}
}
