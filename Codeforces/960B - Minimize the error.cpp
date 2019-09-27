//https://codeforces.com/problemset/problem/960/B

#include <bits/stdc++.h>
using namespace std;

const int N = 1003;
int vet[N];

int main(){
	int n, k1, k2;
	scanf("%d %d %d", &n, &k1, &k2);
	for (int i=0; i<n; i++){
		scanf("%d", &vet[i]);
	}
	for (int i=0; i<n; i++){
		int x;
		scanf("%d", &x);
		vet[i] -= x;
		vet[i] = abs(vet[i]);
	}
	int qtd = k1+k2;
	while (qtd > 0){
		int mx = 0;
		for (int i=1; i<n; i++){
			if(vet[i] > vet[mx]) mx = i;
		}
		vet[mx]--;
		vet[mx] = abs(vet[mx]);
		qtd--;
	}
	long long ans = 0LL;
	for (int i=0; i<n; i++){
		ans += (1LL * vet[i] * vet[i]);
	}
	printf("%lld\n", ans);
}
