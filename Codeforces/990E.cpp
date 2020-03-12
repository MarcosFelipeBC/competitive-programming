#include <bits/stdc++.h>
#define oo 1000000000000000000
using namespace std;

const int N = 1000006;
int vist[N], last[N], vet[N];

int main()
{
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	last[0] = -1;
	for (int i=0; i<m; i++){
		int x;
		scanf("%d", &x);
		vist[x] = 1;
		last[x] = (vist[x-1] == 0) ? x-1 : last[x-1];
	}
	for (int i=1; i<=k; i++) scanf("%d", &vet[i]);
	long long ans = oo;
	for (int i=1; i<=k; i++){
		long long aux = 0, now = 0;
		while (now < n)
		{
			if(vist[now]) {
				aux = oo;
				break;
			}
			now += i;
			aux += vet[i];
			if(now < n && vist[now])
			{
				if(last[now] != -1 && last[now] + i > now)
				{
					now = last[now];
				}
				else {
					aux = oo;
					break;
				}
			}
		}
		ans = min(ans, aux);
	}
	ans = (ans != oo) ? ans : -1;
	printf("%lld", ans);
}	