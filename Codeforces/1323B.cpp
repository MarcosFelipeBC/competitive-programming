#include <bits/stdc++.h>
using namespace std;

const int N = 40004;
int a[N], b[N], qtd[N];

int main(){
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	for (int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	for (int j=0; j<m; j++){
		scanf("%d", &b[j]);
	}
	int cnt = 0;
	for (int i=0; i<n; i++){
		if(a[i] == 1) cnt++;
		if(i == n-1 || a[i+1] == 0)
		{
			for (int j=1; j<=cnt; j++){
				qtd[j] += (cnt-j+1);
			}
			cnt = 0;
		}
	}
	long long ans = 0;
	cnt = 0;
	for (int i=0; i<m; i++){
		if(b[i] == 1) cnt++;
		if(i == m-1 || b[i+1] == 0)
		{
			for (int j=1; j<=cnt; j++){
				if(k%j == 0 && k/j < N){
					ans += (long long)(cnt-j+1) * qtd[k/j];
				}
			}
			cnt = 0;
		}
	}
	printf("%lld\n", ans);
}