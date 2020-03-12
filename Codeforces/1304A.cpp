#include <bits/stdc++.h>
using namespace std;

const int N = 500005;

int main()
{
	int t;
	scanf("%d", &t);
	while (t-- > 0)
	{
		long long x, y, a, b;
		scanf("%lld %lld %lld %lld", &x, &y, &a, &b);
		long long lo = 0, hi = 2000000000, ans = -1;
		while (lo <= hi)
		{
			long long mid = (lo + hi) >> 1;
			if(x + a*mid == y - b*mid){
				ans = mid;
				break;
			}
			else if(x + a*mid < y - b*mid) lo = mid+1;
			else hi = mid-1;
		}
		cout << ans << endl;
	}
}