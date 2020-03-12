//https://codeforces.com/gym/102157/problem/1

#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
typedef long long ll;

ll vet[N];

int check(ll x, const int &n){
	ll sum = 0;
	int qtd = 1;
	for (int i=1; i<n; i++){
		sum += (vet[i] - vet[i-1]);
		if(sum >= x) {
			qtd++;
			sum = 0;
		}
	}
	return qtd;
}

int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i=0; i<n; i++){
		scanf("%lld", &vet[i]);
	}
	sort(vet, vet+n);
	ll lo = 0LL, hi = 1000000000000000000LL, ans = 0LL;
	while (lo <= hi){
		ll mid = (lo + hi) >> 1;
		if(check(mid, n) >= k) {
			ans = mid;
			lo = mid+1;
		}
		else hi = mid-1;
	}
	printf("%lld", vet[0]);
	ll sum = 0LL;
	int qtd = 1;
	for (int i=1; i<n; i++){
		sum += (vet[i] - vet[i-1]);
		if(sum >= ans) {
			sum = 0LL;
			if(qtd < k) printf(" %lld", vet[i]);
			qtd++;
		}
	}
	printf("\n");
}
