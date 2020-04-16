//https://neps.academy/contest/215/problem/681

#include <bits/stdc++.h>
using namespace std;
const int N = 100005;

int vet[N];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i=0; i<n; i++) scanf("%d", &vet[i]);
	sort(vet, vet+n);
	int pos = -1;
	double mx = 0;
	for (int i=2; i<n; i++){
		if(vet[i] < vet[i-1] + vet[i-2]){
			double sp = vet[i] + vet[i-1] + vet[i-2];
			double a = vet[i], b = vet[i-1], c = vet[i-2];
			if(sp * (sp-a) * (sp-b) * (sp-c) > mx) {
				pos = i;
			}
		}
	}
	printf("%d %d %d\n", vet[pos-2], vet[pos-1], vet[pos]);
}