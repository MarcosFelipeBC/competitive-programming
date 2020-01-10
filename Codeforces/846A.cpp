#include <bits/stdc++.h>
using namespace std;

const int N = 110;
int vet[N];

int main(){
	int n;
	scanf("%d", &n);
	for (int i=0; i<n; i++){
		scanf("%d", &vet[i]);
	}
	int ans = 0;
	for (int fix = 0; fix <= n; fix++){
		int less = 0;
		for (int i=0; i<fix; i++){
			if(vet[i] == 1) less++;
		}
		for (int i=fix; i<n; i++){
			if(vet[i] == 0) less++;
		}
		ans = max(ans, n - less);
	}
	printf("%d", ans);
}