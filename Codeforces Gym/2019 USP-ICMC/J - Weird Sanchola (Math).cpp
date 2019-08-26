//https://codeforces.com/gym/102302/problem/J

#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
long long vet[N];
int n;

bool prime(int x){
	if(x == 1) return false;
	for (int i=2; i*i<=x; i++){
		if(x%i == 0) return false;
	}
	return true;
}

long long calc(long long x){
	long long ans = 0LL;
	for (int i=0; i<n; i++){
		ans += (abs(vet[i] - x));
	}
	return ans;
}

int main(){
	scanf("%d", &n);
	long long average = 0LL;
	for (int i=0; i<n; i++){
		scanf("%lld", &vet[i]);
	}	
	sort(vet, vet+n);
	average = vet[n/2];
	if(n%2 == 0) average = (average + vet[n/2-1])/2LL;
	long long hi = average, lo = average;
	while (!prime(hi)) hi++;
	while (lo > 1 && !prime(lo)) lo--;
	if(lo >= 2) {
		printf("%lld\n", min(calc(lo), calc(hi)));
	}
	else {
		printf("%lld\n", calc(hi));
	}
}
