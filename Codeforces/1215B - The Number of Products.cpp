//https://codeforces.com/problemset/problem/1215/B

#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	int qtd = 0, pares = 1, impares = 0;
	long long ansNegative = 0LL, ansPositive = 0LL;
	for (int i=0; i<n; i++){
		int x;
		scanf("%d", &x);
		if(x < 0) qtd++;
		if(qtd & 1){
			ansNegative += pares;
			impares++;
		}
		else {
			ansNegative += impares;
			pares++;
		}
	}
	ansPositive = (1LL * n * (n+1))/2 - ansNegative;
	printf("%lld %lld\n", ansNegative, ansPositive);
}
