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
		for (int i=2; i<30; i++){
			int pot = (1 << i)-1;
			if(n%pot == 0) {
				printf("%d\n", n/pot);
				break;
			}
		}
	}
}