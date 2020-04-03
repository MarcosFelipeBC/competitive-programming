//https://atcoder.jp/contests/abc160/tasks/abc160_b

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	long long ans = 1000LL * (n/500);
	n %= 500;
	ans += 5 * (n/5);
	printf("%lld\n", ans);
}