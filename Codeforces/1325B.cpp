#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
int vet[N];

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n;
		scanf("%d", &n);
		for (int i=0; i<n; i++){
			scanf("%d", &vet[i]);
		}
		int ans = 0;
		sort(vet, vet+n);
		for (int i=0; i<n; i++){
			if(i == 0 || vet[i] != vet[i-1]) ans++;
		}
		printf("%d\n", ans);
	}
}