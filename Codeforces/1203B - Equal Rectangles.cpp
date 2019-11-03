//https://codeforces.com/contest/1203/problem/B

#include <bits/stdc++.h>
using namespace std;

const int N = 101;
int vet[4*N];

int main(){
	int t;
	scanf("%d", &t);
	while (t--){
		int n;
		scanf("%d", &n);
		for (int i=0; i<4*n; i++){
			scanf("%d", &vet[i]);
		}
		sort(vet, vet+4*n);
		int p1 = 0, p2 = 4*n-1;
		int sz = vet[p1] * vet[p2];
		bool flag = true;
		for (int i=0; i<n; i++){
			if(vet[p1] != vet[p1+1] || vet[p2] != vet[p2-1] || vet[p1] * vet[p2] != sz){
				flag = false;
				break;
			}
			p1 += 2, p2 -= 2;
		}
		puts((flag) ? "YES" : "NO");
	}
}
