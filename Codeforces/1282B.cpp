#include <bits/stdc++.h>
using namespace std;

int vet[202020], acc[202020];

int main(){
	int t;
	scanf("%d", &t);
	while (t-- > 0){
		int n, p, k;
		scanf("%d %d %d", &n, &p, &k);
		for (int i=1; i<=n; i++){
			scanf("%d", &vet[i]);
		}
		sort(vet+1, vet+1+n);
		for (int i=1; i<=n; i++){
			acc[i] = vet[i];
			acc[i] += acc[i-1];
		}
		for (int i=1; i<=k; i++){
			
		}
		int ans = 0;
		for (int i=1; i<=n; i++){
			int qtd = i/k;
			int pego = i-qtd*k;
			// cout << i << ' ' << acc[pego] << ' ' << acc[i] << ' ' << acc[i-qtd] << endl;
			if(acc[pego] + acc[i] - acc[i-qtd] <= p) ans = i;
		}
		printf("%d\n", ans);
	}
}