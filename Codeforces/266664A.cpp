#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	int mn = 10000;
	int ans = 0;
	for (int i=0; i<n; i++){
		int x;
		scanf("%d", &x);
		if(!(x&1)) x--;
		mn = min(x, mn);
		ans += x;
	}
	if(!(n & 1)) ans -= mn;
	printf("%d", ans);
}