//https://codeforces.com/gym/102302/problem/B

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	ll a, b;
	scanf("%lld %lld", &a, &b);
	vector < ll > ans;
	for (ll i=1; i*i<=a; i++){
		if(a%i == 0){
			if(i%b == 0) ans.push_back(i);
			if(i*i != a && (a/i)%b == 0) ans.push_back(a/i);
		}
	}
	sort(ans.begin(), ans.end());
	for (int i=0; i<ans.size(); i++){
		if(i) printf(" ");
		printf("%lld", ans[i]);
	}
	puts("");
}
