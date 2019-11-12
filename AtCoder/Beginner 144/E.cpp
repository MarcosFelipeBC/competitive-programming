#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 200005;
int vet[N], vet2[N];

int main(){
	int n;
	ll k;
	scanf("%d %lld", &n, &k);
	for (int i=0; i<n; i++){
		scanf("%d", &vet[i]);
	}
	for (int i=0; i<n; i++){
		scanf("%d", &vet2[i]);
	}
	sort(vet2, vet2+n, greater < int >());
	sort(vet, vet+n);
	ll lo = 0, hi = 1000000000000000, ans = -1;
	while (lo <= hi){
		ll mid = (lo + hi) >> 1;
		long long auxK = k;
		bool flag = true;
		for (int i=0; i<n; i++){
			ll num = mid/(ll)vet2[i];
			if((ll)vet[i]-num > auxK){
				flag = false;
				break;
			}
			else auxK -= (max(0LL, (ll)vet[i]-num));
		}
		if(flag) {
			hi = mid-1;
			ans = mid;
		}
		else lo = mid+1;
	}
	printf("%lld\n", ans);
}
