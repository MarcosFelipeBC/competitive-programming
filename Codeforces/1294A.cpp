#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	scanf("%d", &t);
	while (t-- > 0){
		int a, b, c, n;
		scanf("%d %d %d %d", &a, &b, &c, &n);
		if((a+b+c+n)%3 == 0 && (a+b+c+n)/3 >= max(a, max(b, c))) puts("YES");
		else puts("NO");
	}
}