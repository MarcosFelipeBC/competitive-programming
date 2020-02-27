#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod = 1000000000000000009;
const ll A = 1009;
const int N = 500005;

ll h[N], p[N], rh[N];

ll mult(ll a, ll b)
{
	ll q = (long double)a * b/mod;
	ll r = a*b - q*mod;
	while (r < 0) r += mod;
	while (r >= mod) r -= mod;
	return r;
}

ll get(int l, int r)
{
	if(l == 0) return h[r];
	return (h[r] - mult(h[l-1], p[r-l+1])%mod + mod)%mod;
}

ll getrev(int l, int r)
{
	if(l == 0) return rh[r];
	return (rh[r] - mult(rh[l-1], p[r-l+1])%mod + mod)%mod;	
}


int main(){
	int n, m;
	cin >> n >> m;
	string str;
	cin >> str;
	h[0] = str[0], p[0] = 1LL;
	for (int i=1; i<n; i++){
		h[i] = (str[i] + mult(h[i-1], A))%mod;
	}
	reverse(str.begin(), str.end());
	rh[0] = str[0];
	for (int i=1; i<n; i++){
		rh[i] = (str[i] + mult(rh[i-1], A))%mod;
		p[i] = mult(p[i-1], A)%mod;
	}
	p[n] = mult(p[n-1], A)%mod;
	bool flag = false;
	int r = n-1;
	for (int i=0; i+m-1<n; i++){
		if(get(i, i+m-1) == getrev(r-m+1, r)) {
			flag = true;
			break;
		}
		r--;
	}
	cout << (flag ? "accept" : "reject") << endl; 
}