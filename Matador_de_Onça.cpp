#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

typedef long long ll;
const int N = 1005;
ll dp[N], vet[N];
int n;

ll back(int pos) {
	if(pos == n) return 0;
	ll &ans = dp[pos];
	if(ans != -1) return ans;
	ans = 0;
	ll maior = -INF, menor = INF;
	for (int i=pos; i<n; i++){
		maior = max(maior, vet[i]);
		menor = min(menor, vet[i]);
		ans = max(ans, (maior - menor) + back(i+1));
	}
	return ans;
}

int main(){
	scanf("%d", &n);
	for (int i=0; i<n; i++){
		scanf("%lld", &vet[i]);
	}
	memset(dp, -1LL, sizeof dp);
	printf("%lld\n", back(0));
}
