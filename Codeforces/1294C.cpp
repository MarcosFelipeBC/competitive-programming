#include <bits/stdc++.h>
using namespace std;

int Divisor(int x, int last)
{
	for (int i=2; i*i < x; i++){
		if(x%i == 0) {
			if(i != last && x/i != last) return i;
		}
	}
	return -1;
}

int main()
{
	int t;
	scanf("%d", &t);
	while (t-- > 0)
	{
		int n;
		scanf("%d", &n);
		bool flag = false;
		for (int i=2; i*i < n; i++){
			if(n%i == 0){
				int a = Divisor(i, n/i);
				if( a != -1){
					flag = true;
					printf("YES\n%d %d %d\n", i/a, n/i, a);
					break;
				}
				a = Divisor(n/i, i);
				if(a != -1){
					flag = true;
					printf("YES\n%d %d %d\n", i, n/i/a, a);
					break;
				}
			}
		}
		if(!flag) puts("NO");
	}	
}