//https://codeforces.com/contest/1245/problem/A

#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	scanf("%d", &t);
	while (t-- > 0){
		int a, b;
		scanf("%d %d", &a, &b);
		if(__gcd(a, b) != 1) puts("Infinite");
		else puts("Finite");
	}
}
