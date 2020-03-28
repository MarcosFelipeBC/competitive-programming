//https://atcoder.jp/contests/abc133/tasks/abc133_c

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int l, r;
	scanf("%d %d", &l, &r);
	if(r-l+1 >= 2019) printf("0\n");
	else {
		int ans = 2020;
		for (int i=l; i<=r; i++){
			for (int j=i+1; j<=r; j++){
				ans = min(ans, ((i%2019) *(j%2019))%2019);
			}
		}
		printf("%d\n", ans);
	}
}