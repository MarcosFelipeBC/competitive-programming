#include <bits/stdc++.h>
using namespace std;

int main()
{
	int k;
	scanf("%d", &k);
	int ans = 0;
	for (int a=1; a<=k; a++){
		for (int b=1; b<=k; b++){
			for (int c=1; c<=k; c++){
				ans += __gcd(a, __gcd(b, c));
			}
		}
	}
	printf("%d\n", ans);
}