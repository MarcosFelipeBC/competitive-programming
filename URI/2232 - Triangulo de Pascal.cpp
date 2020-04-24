#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	scanf("%d", &t);
	while (t-- > 0)
	{
		int x;
		scanf("%d", &x);
		printf("%d\n", (1 << x)-1);
	}
}