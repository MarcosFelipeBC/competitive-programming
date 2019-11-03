//https://codeforces.com/contest/1203/problem/A

#include <bits/stdc++.h>
using namespace std;

const int N = 202;
int vet[N];

int main(){
	int q;
	scanf("%d", &q);
	while (q-- > 0){
		int n;
		scanf("%d", &n);
		for (int i=0; i<n; i++){
			scanf("%d", &vet[i]);
		}
		bool f1 = true, f2 = true;
		for (int i=0; i<n-1; i++){
			if(vet[i] == n){
				if(vet[i+1] != 1) f1 = false;
			}
			else if(vet[i+1] != vet[i]+1) f1 = false;
		}
		if(vet[n-1] == n) {
			if(vet[0] != 1) f1 = false;
		}
		else if(vet[0] != vet[n-1]+1) f1 = false;
		for (int i=1; i<n; i++){
			if(vet[i] == n) {
				if(vet[i-1] != 1) f2 = false;
			}
			else if(vet[i-1] != vet[i]+1) f2 = false;
		}
		if(vet[0] == n) {
			if(vet[n-1] != 1) f2 = false;
		}
		else if(vet[n-1] != vet[0]+1) f2 = false;
		puts((f1 || f2) ? "YES" : "NO");
	}
}
