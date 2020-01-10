#include <bits/stdc++.h>
using namespace std;

int vet[101010];

int main(){
	int n;
	scanf("%d", &n);
	long long sum = 0;
	for (int i=0; i<n; i++){
		scanf("%d", &vet[i]);
		sum += vet[i];
	}
	sort(vet, vet+n);
	long long sum2 = 0;
	for (int i=0; i<n/2; i++){
		sum2 += vet[i];
	}
	sum -= sum2;
	printf("%lld\n", sum*sum + sum2*sum2);
}