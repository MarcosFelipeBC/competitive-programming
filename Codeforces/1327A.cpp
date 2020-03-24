#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int main()
{
	int t;
	scanf("%d", &t);
	while (t-- > 0)
	{
		long long n, k;
		scanf("%lld %lld", &n, &k);
		long long sum = ((1 + (2*(k-1))-1) * (k-1))/2LL;
		if(sum >= n) puts("NO");
		else {
			int resto = n-sum;
			if(resto%2 == 1 && resto > 2*(k-1)-1) puts("YES");
			else puts("NO");
		}
	}
}