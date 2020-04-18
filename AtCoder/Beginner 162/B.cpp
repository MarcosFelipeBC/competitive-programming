#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	long long ans = 0LL;
	for (int i=1; i<=n; i++){
		if(i%3 != 0 && i%5 != 0) ans += i;
	}
	printf("%lld\n", ans);
}