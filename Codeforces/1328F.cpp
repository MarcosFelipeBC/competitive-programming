#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
long long vet[N];
long long go[N], come[N];

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i=0; i<n; i++) {
		scanf("%lld", &vet[i]);
	}
	sort(vet, vet+n);
	go[0] = 0;
	int cnt = 1;
	for (int i=1; i<n; i++){
		if(vet[i] != vet[i-1]){
			if(cnt >= k) {
				puts("0");
				return 0;
			}
			go[i] = go[i-1] + i*(vet[i] - vet[i-1]);
			cnt = 1;
		}
		else go[i] = go[i-1], cnt++;
	}
	come[n-1] = 0;
	for (int i=n-2; i>=0; i--){
		if(vet[i] != vet[i+1]){
			come[i] = come[i+1] + (n-1 - i) * (vet[i+1] - vet[i]);
		}
		else come[i] = come[i+1];
	}
	long long ans = 0x3f3f3f3f3f3f3f3f;
	for (int i=0; i<n; i++){
		int cnt = 1;
		while (i < n-1 && vet[i+1] == vet[i]) i++, cnt++;
		if(i == n-1) ans = min(ans, go[n-1]);
		else {
			if(k <= i+1){
				ans = min(ans, go[i] - min(i+1 - k, i+1 - cnt));
			}
			else {
				long long resp = go[i];
				int dif = k - (i+1);
				if(dif > n-1 - i) continue ;
				resp += (come[i+1] + (long long)(n-1 - i)*(vet[i+1] - vet[i] - 1) + dif);
				ans = min(ans, resp);
			}
		}
	}
	for (int i=n-1; i>=0; i--){
		int cnt = 1;
		while (i > 0 && vet[i] == vet[i-1]) i--, cnt++;
		if(i == 0) ans = min(ans, come[0]);
		else {
			if(k <= n-i) {
				ans = min(ans, come[i] - min(n-i - k, n-i- cnt));
			}
			else {
				long long resp = come[i];
				int dif = k - (n-i);
				if(dif > i) continue ;
				resp += (go[i-1] + i*(vet[i] - vet[i-1] - 1) + dif);
				ans = min(ans, resp);
			}
		}
	}
	printf("%lld\n", ans);
}