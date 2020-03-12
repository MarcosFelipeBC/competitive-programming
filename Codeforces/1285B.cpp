#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 100005;
ll vet[N];

int main(){
	int t;
	scanf("%d", &t);
	while (t-- > 0){
		int n;
		scanf("%d", &n);
		ll sum = 0;
		for (int i=0; i<n; i++){
			scanf("%lld", &vet[i]);
			sum += vet[i];
		}
		ll mn1 = 0;
		ll acc1 = 0;
		ll mx1 = -10000000000000000;
		for (int i=0; i<n-1; i++){
			acc1 += vet[i];
			mx1 = max(mx1, acc1 - mn1);
			mn1 = min(mn1, acc1);
		}
		ll mn2 = 0;
		ll acc2 = 0;
		ll mx2 = -10000000000000000;
		for (int i=1; i<n; i++){
			acc2 += vet[i];
			mx2 = max(mx2, acc2 - mn2);
			mn2 = min(mn2, acc2);
		}
		puts((max(mx1, mx2) < sum) ? "YES" : "NO");
	}
}