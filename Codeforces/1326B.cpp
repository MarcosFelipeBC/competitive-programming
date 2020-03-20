#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
int b[N], a[N];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i=0; i<n; i++) scanf("%d", &b[i]);
	int mx = b[0];
	a[0] = b[0];
	printf("%d", a[0]);
	for (int i=1; i<n; i++){
		a[i] = b[i] + mx;
		mx = max(mx, a[i]);
		printf(" %d", a[i]);
	}
	puts("");
}