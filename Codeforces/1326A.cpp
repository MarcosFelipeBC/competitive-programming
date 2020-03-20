#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int main()
{
	int t;
	scanf("%d", &t);
	while (t--> 0)
	{
		int n;
		scanf("%d", &n);
		if(n == 1) printf("-1\n");
		else {
			printf("5");
			for (int i=1; i<n; i++) printf("3");
			puts("");
		}
	}
}