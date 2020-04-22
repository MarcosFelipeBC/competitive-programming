#include <bits/stdc++.h>
#define oo 0x3f3f3f3f
using namespace std;

const int N = 200005;
int vet[N];

int main()
{
	int t;
	scanf("%d", &t);
	while (t-- > 0){
		int n;
		scanf("%d", &n);
		for (int i=0; i<n; i++){
			scanf("%d", &vet[i]);
		}
		long long ans = 0LL;
		int mx = -oo;
		for (int i=0; i<n; i++){
			if(i && (vet[i] > 0) != (vet[i-1] > 0)){
				ans += mx;
				mx = -oo;
			}
			mx = max(mx, vet[i]);
		}
		ans += mx;
		printf("%lld\n", ans);
	}
}