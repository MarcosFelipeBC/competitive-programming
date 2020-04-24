#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	int x, y, z;
	scanf("%d %d %d", &x, &y, &z);
	int ans = max(0, x-a) + max(0, y-b) + max(0, z-c);
	printf("%d\n", ans);
}