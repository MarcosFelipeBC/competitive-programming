//https://codeforces.com/contest/1203/problem/C

#include <bits/stdc++.h>
using namespace std;

const int N = 400005;
typedef long long ll;
ll vet[N];

int main(){
	int n;
	scanf("%d", &n);
	ll gcd = 0;
	for (int i=0; i<n; i++){
		scanf("%lld", &vet[i]);
		gcd = __gcd(gcd, vet[i]);
	}
	int ans = 2;
	if(gcd == 1) ans = 1;
	for (ll i=2; i*i<=gcd; i++){
		if(gcd%i == 0){
			ans++;
			if(i*i != gcd) ans++;
		}
	}
	printf("%d\n", ans);
}
