#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	scanf("%d", &t);
	while (t-- > 0){
		int a, b, c, r;
		scanf("%d %d %d %d", &a, &b, &c, &r);
		if(b < a) swap(a, b); 
		int L = max(c - r, a);
		int R = min(c+r, b);
		if(L > b || R < a){
			printf("%d\n", b-a);
			continue ;
		}
		if(L > R) printf("0\n");
		else printf("%d\n", b - a - (R-L));
	}
}