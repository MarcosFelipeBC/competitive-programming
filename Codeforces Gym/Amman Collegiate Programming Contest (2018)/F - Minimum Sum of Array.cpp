//https://codeforces.com/gym/101810/problem/F

#include <bits/stdc++.h>
using namespace std;

const int M = 1000006;
const int N = 100005;
int f[M], vet[N];

int main(){
	int t;
	scanf("%d", &t);
	while (t-- > 0){
	int n;
	scanf("%d", &n);
	int mx = -1;
	long long sum = 0LL;
	for (int i=0; i<n; i++){
		scanf("%d", &vet[i]);
		mx = max(mx, vet[i]);
		sum += vet[i];
		f[vet[i]]++;
	}
	for (int i=1; i<mx; i++){
		if(!f[i]) continue ;
		for (int j=i+i; j<=mx; j+=i){
			sum -= (j-i)*f[j];
			f[j] = 0;
		}
	}
	printf("%lld\n", sum);
	for (int i=0; i<n; i++) if(f[vet[i]]) f[vet[i]] = 0;
}
