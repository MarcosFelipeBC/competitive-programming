//https://atcoder.jp/contests/abc161/tasks/abc161_c

#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long a, b;
	scanf("%lld %lld", &a, &b);
	a %= b;
	printf("%lld\n", min(a, -(a-b)));
}