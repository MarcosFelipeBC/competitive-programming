#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	scanf("%d", &t);
	while (t-- > 0){
		int n, a, b;
		scanf("%d %d %d", &n, &a, &b);
		if(n <= a) puts("1");
		else if(b >= a) puts("-1");
		else {
			int now = 0;
			int ans = 0;
			while (now < n){
				ans++;
				now += a;
				if(now >= n) break;
				now -= b;
			}
			printf("%d\n", ans);
		}
	}
}
