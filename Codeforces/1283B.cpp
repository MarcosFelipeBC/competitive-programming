#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	scanf("%d", &t);
	while (t-- > 0){
		int n, k;
		scanf("%d %d", &n, &k);
		int ans = max(0, (n%k) - k/2);
		printf("%d\n", n-ans);
	}
}