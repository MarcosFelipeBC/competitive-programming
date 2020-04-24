#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	int ans = 0;
	for (int i=0; i<n; i++){
		int l, c;
		scanf("%d %d", &l, &c);
		ans += ((l > c) ? c : 0);
	}
	printf("%d\n", ans);
}