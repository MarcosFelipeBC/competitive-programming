#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, d;
	scanf("%d %d", &n, &d);
	int ans = 0;
	for (int i=1; i<=n; i += (2*d+1)){
		ans++;
		if(i+d > n) break;
	}
	printf("%d\n", ans);
}
