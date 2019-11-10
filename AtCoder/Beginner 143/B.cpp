#include <bits/stdc++.h>
using namespace std;

const int N = 55;
int vet[N];

int main(){
	int n;
	scanf("%d", &n);
	int sum = 0;	
	for (int i=0; i<n; i++){
		scanf("%d", &vet[i]);
		sum += vet[i];
	}
	int ans = 0;
	for (int i=0; i<n; i++){
		ans += ((sum - vet[i]) * vet[i]);
	}
	printf("%d\n", ans/2);
}
