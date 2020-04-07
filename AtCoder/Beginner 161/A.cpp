//https://atcoder.jp/contests/abc161/tasks/abc161_a

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	swap(a, b);
	swap(a, c);
	printf("%d %d %d\n", a, b, c);
}