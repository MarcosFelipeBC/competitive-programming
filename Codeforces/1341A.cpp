#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	scanf("%d", &t);
	while (t-- > 0)
	{
		int n, a, b, c, d;
		scanf("%d %d %d %d %d", &n, &a, &b, &c, &d);
		bool ans = false;
		for (int i=c-d; i<=c+d; i++){
			if(abs(i - a*n) <= b*n) ans = true;
		}
		puts((ans) ? "Yes" : "No");
	}
}