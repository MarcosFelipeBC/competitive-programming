//https://atcoder.jp/contests/abc161/tasks/abc161_b

#include <bits/stdc++.h>
using namespace std;

const int N = 101;
int vet[N];

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	int sum = 0;
	for (int i=0; i<n; i++){
		scanf("%d", &vet[i]);
		sum += vet[i];
	}
	int div = sum/(m*4);
	if(sum%(m*4) != 0) div++;
	int qtd = 0;
	for (int i=0; i<n; i++){
		if(vet[i] >= div) qtd++;
	}
	if(qtd >= m) puts("Yes");
	else puts("No");
}