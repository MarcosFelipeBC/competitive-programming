#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n, m, x, y;
		scanf("%d %d %d %d", &n, &m, &x, &y);
		int ans = 0;
		ans = max(ans, x*m);
		ans = max(ans, y*n);
		ans = max(ans, (n-x-1) * m);
		ans = max(ans, (m-y-1)*n);
		printf("%d\n", ans);
	}
}