#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
int vet[N], qtd[1000006];

int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i=0; i<n; i++){
		scanf("%d", &vet[i]);
		qtd[vet[i]]++;
	}
	sort(vet, vet+n);
	int ans = 0;
	for (int i=1; i<n; i++){
		if(vet[i] > vet[i-1] && vet[i-1]+k >= vet[i]){
			ans+=qtd[vet[i-1]];
		}
	}
	printf("%d\n", n-ans);
}