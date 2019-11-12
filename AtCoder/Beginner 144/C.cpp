#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	ll n;
	scanf("%lld", &n);
	ll ans = n-1;
	for (ll i=2; i*i<=n; i++){
		if(n%i == 0){
			ans = min(ans, (i-1 + n/i-1));
		}
	}
	printf("%lld\n", ans);
}
