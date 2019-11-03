//https://codeforces.com/contest/1203/problem/E

#include <bits/stdc++.h>
using namespace std;

const int N = 150005;
int vet[N];

int main(){
	int n;
	scanf("%d", &n);
	for (int i=0; i<n; i++){
		scanf("%d", &vet[i]);
	}
	sort(vet, vet+n);
	if(vet[0] > 1) vet[0]--;
	int last = vet[0];
	int ans = 1;
	for (int i=1; i<n; i++){
		if(vet[i] - last > 1){
			vet[i]--;
			ans++;
			last = vet[i];
		}
		else if(vet[i] - last == 1){
			ans++;
			last = vet[i];
		}
		else if(vet[i] - last == 0) {
			vet[i]++;
			ans++;
			last = vet[i];
			
		}
		else continue ;
	}
	printf("%d\n", ans);
}

