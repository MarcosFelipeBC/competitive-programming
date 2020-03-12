#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
bool f(ll n, ll d, ll x){
	return (n >= x + (d/(x+1)) + (d%(x+1) != 0));
}

int main(){
	int t;
	scanf("%d", &t);
	while (t-- > 0){
		ll n, d;
		scanf("%lld %lld", &n, &d);
		bool ans = false;
		for (int i=0; i<sqrt(d)+10; i++){
			ans = (ans | f(n, d, i));
		}
		puts((ans) ? "YES" : "NO");
	}
}