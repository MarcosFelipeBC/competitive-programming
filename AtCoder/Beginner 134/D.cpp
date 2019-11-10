#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
bitset < N > vet, tem;

int main(){
	int n;
	scanf("%d", &n);
	int x;
	for (int i=1; i<=n; i++){
		scanf("%d", &x);
		vet[i] = x;
		tem[i] = 0;
	}
	vector < int > ans;
	for (int i=n; i>0; i--){
		int qtd = 0;
		for (int j=i+i; j<=n; j+=i){
			qtd += tem[j];
		}
		if(qtd%2 != vet[i]){
			tem[i] = 1;
			ans.push_back(i);
		}
	}
	printf("%d", (int)ans.size());
	for (int i=0; i<ans.size(); i++){
		if(i) printf(" ");
		else printf("\n");
		printf("%d", ans[i]);
	}
	puts("");
	return 0;
}
