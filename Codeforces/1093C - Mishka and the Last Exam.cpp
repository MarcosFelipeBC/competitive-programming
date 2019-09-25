//https://codeforces.com/contest/1093/problem/C

#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
long long b[N], a[N];

int main(){
	int n;
	scanf("%d", &n);
	for (int i=0; i<n/2; i++){
		scanf("%lld", &b[i]);
	}
	int l = 1, r = n-2;
	a[0] = 0, a[n-1] = b[0];
	for (int i=1; i<n/2; i++){
		a[l] = 0LL, a[r] = b[i];
		if(a[l] < a[l-1]){
			long long dif = a[l-1] - a[l];
			a[l] += dif;
			a[r] -= dif;
		}
		if(a[r] > a[r+1]){
			long long dif = a[r] - a[r+1];
			a[r] -= dif;
			a[l] += dif;
		}
		l++, r--;
	}
	for (int i=0; i<n; i++){
		printf("%lld ", a[i]);
	}
	printf("\n");
	return 0;
}
