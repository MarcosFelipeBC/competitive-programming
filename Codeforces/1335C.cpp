#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
int vet[N], qtd[N];

int main()
{
	int t;
	scanf("%d", &t);
	while (t-- > 0)
	{
		memset(qtd, 0, sizeof qtd);
		int n;
		scanf("%d", &n);
		int mx = -1;
		int dif = 0;
		for (int i=0; i<n; i++){
			scanf("%d", &vet[i]);
			qtd[vet[i]]++;
			if(qtd[vet[i]] == 1) dif++;
			if(mx == -1 || qtd[mx] < qtd[vet[i]]) mx = vet[i];
		}
		if(dif - 1 >= qtd[mx]) printf("%d\n", qtd[mx]);
		else if(dif >= qtd[mx]-1) printf("%d\n", qtd[mx]-1);
		else printf("%d\n", dif);
	}
}