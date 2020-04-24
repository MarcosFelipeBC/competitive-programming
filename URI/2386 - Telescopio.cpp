#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a, n;
	scanf("%d\n%d", &a, &n);
	int ans = 0;
	for (int i=0; i<n; i++){
		int x;
		scanf("%d", &x);
		ans += (a*x >= 40000000);
	}
	printf("%d\n", ans);
}