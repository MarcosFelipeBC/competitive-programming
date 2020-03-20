//https://www.spoj.com/problems/ADACLEAN/
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
const int A = 1009;
const int N = 100005;
const ll mod = 1000000000000000009;
 
ll h[N], p[N];
 
ll mult(ll a, ll b)
{
	ll q = (long double)a*b/mod;
	ll r = a*b - mod*q;
	while (r < 0) r += mod;
	while (r >= mod) r -= mod;
	return r;
}
 
ll get(int l, int r)
{
	if(l == 0) return h[r];
	return (h[r] - mult(h[l-1], p[r-l+1]) + mod)%mod;
}
 
int main()
{
	int t;
	cin >> t;
	while (t--){
		int n, k;
		cin >> n >> k;
		string str;
		cin >> str;
		h[0] = str[0], p[0] = 1LL;
		for (int i=1; i<n; i++){
			h[i] = (str[i] + mult(h[i-1], A))%mod;
			p[i] = mult(p[i-1], A);
		}
		set < ll > s;
		for (int i=0; i+k-1 < n; i++){
			s.insert(get(i, i+k-1));
		}
		cout << s.size() << endl;
	}
}
