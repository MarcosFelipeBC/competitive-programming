#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	scanf("%d", &t);
	while (t-- > 0){
		int n;
		scanf("%d", &n);
		int mn = 2e9, mx = 0;
		for (int i=0; i<n; i++){
			int l, r;
			scanf("%d %d", &l, &r);
			mx = max(l, mx);
			mn = min(r, mn);
		}
		if(n == 1) mx = 0, mn = 0;
		printf("%d\n", max(0, mx-mn));
	}
}
