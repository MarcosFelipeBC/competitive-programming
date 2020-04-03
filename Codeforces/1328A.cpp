#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	scanf("%d", &t);
	while (t-- > 0)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		int x = a/b;
		if(a%b == 0) printf("0\n");
		else {
			printf("%d\n", b*(x+1) - a);
		}
	}
}