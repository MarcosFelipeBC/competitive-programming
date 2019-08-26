//https://codeforces.com/contest/1207/problem/F

#include <bits/stdc++.h>
using namespace std;

const int M = 707;
const int N = 500005;

long long vet[N];
long long memo[M+5][M+5];

int main(){
	int q;
	scanf("%d", &q);
	while (q-- > 0){
		int t, x;
		long long y;
		scanf("%d %d %lld", &t, &x, &y);
		if(t == 1){
			for (int i=1; i<=M; i++){
				memo[i][x%i] += y;
			}
			vet[x] += y;
		}
		else {
			long long ans = 0LL;
			if(x <= M) ans = memo[x][y];
			else {
				for (int i=y; i<N; i+=x){
					ans += vet[i]; 
				}
			}
			printf("%lld\n", ans);
		}
	}
}
