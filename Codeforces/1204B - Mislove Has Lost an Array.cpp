//https://codeforces.com/problemset/problem/1204/B

#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, l, r;
	scanf("%d %d %d", &n, &l, &r);
	long long sumMn = 0LL, sumMx = 0LL;
	for (int i=0; i<l; i++){
		sumMn += (1LL << i);
	}
	sumMn += (n-l);
	for (int i=0; i<r ;i++){
		sumMx += (1LL << i);
	}
	sumMx += ((n-r)*(1LL << (r-1)));
	printf("%lld %lld\n", sumMn, sumMx);
}
