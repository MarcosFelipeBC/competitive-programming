#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	scanf("%d", &t);
	while (t-- > 0)
	{
		int n;
		scanf("%d", &n);
		if(n%4 == 0){
			puts("YES");
			int sum = 0;
			for (int i=0, x = 2; i<n/2; i++, x+=2){
				printf("%d ", x);
				sum += x;
			}
			for (int i=0, x = 1; i<n/2-1; i++, x+=2){
				printf("%d ", x);
				sum -= x;
			}
			printf("%d\n", sum);
		}
		else puts("NO");
	}
}