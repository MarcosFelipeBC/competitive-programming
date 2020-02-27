#include <bits/stdc++.h>
using namespace std;

const int N = 2000005;
int mx[N], sum[N];

int main()
{
	for (int i=1; i<=2000000; i++){
		for (int j=i; j<=2000000; j+=i){
			sum[j] += i;
		}
	}
	mx[0] = -1;
	for (int i=1; i<=2000000; i++){
		mx[i] = mx[i-1];
		if(sum[i]-i == i) mx[i] = i;
	}
	int t;
	scanf("%d", &t);
	while (t-- > 0)
	{
		int n;
		scanf("%d", &n);
		printf("%d\n", mx[n]);
	}
}
