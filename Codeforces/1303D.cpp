#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 100005;
int vet[N], qtd[30];

int main(){
	int x = 10;
	int t;
	scanf("%d", &t);
	while (t-- > 0){
		ll m;
		scanf("%lld", &m);
		int n;
		scanf("%d", &n);
		for (int i=0; i<n; i++){
			scanf("%d", &x);
			qtd[x]++;
		}
		int ans = 0;
		for (int i=0; i<60; i++){
			if((m & (1 << i)) == 0) continue ;
			for (int i=0; i<n; i++){
				
			}
		}
	}
}