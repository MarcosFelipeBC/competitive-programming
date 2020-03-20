#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1000006;
const ll A = 1009;
const ll mod = 1000000000000000009;

ll h[2][N], p[N];

ll mult(ll a, ll b)
{
	ll q = (long double)a*b/mod;
	ll r = a*b - mod*q;
	while (r < 0) r += mod;
	while (r >= mod) r -= mod;
	return r;
}

ll get(int idx, int l, int r)
{
	if(l == 0) return h[idx][r];
	return (h[idx][r] - mult(h[idx][l-1], p[r-l+1]) + mod)%mod;
}

void process(const string& str)
{
	string aux = str;
	reverse(aux.begin(), aux.end());
	h[0][0] = str[0], h[1][0] = aux[0], p[0] = 1LL;
	for (int i=1; i<str.size(); i++){
		h[0][i] = (str[i] + mult(h[0][i-1], A))%mod;
		h[1][i] = (aux[i] + mult(h[1][i-1], A))%mod;
		p[i] = mult(p[i-1], A);
	}
	p[str.size()] = mult(p[str.size()-1], A);
}

bool solve(const string &str, int sz)
{
	if(sz > str.size()) return false;
	int n = str.size();
	if(get(0, 0, sz-1) == get(1, n-sz ,n-1)) return true;
	if(get(0, n-sz, n-1) == get(1, 0, sz-1)) return true;
	return false;
}

string findGreater(const string& str)
{
	process(str);
	int n = str.size();
	for (int i=str.size()-1; i>=0; i--){
		if(get(0, 0, i) == get(1, n-i-1, n-1)) return str.substr(0, i+1);
		if(get(1, 0, i) == get(0, n-i-1, n-1)) return str.substr(n-i-1, i+1);
	}
	return "";
}

int main()
{
	int t;
	cin >> t;
	while (t-- > 0)
	{
		string s;
		cin >> s;
		int n = s.size();
		int l=0, r=n-1;
		while (l < r && s[l] == s[r]){
			l++, r--;
		}
		string a = s.substr(0, l);
		string c = s.substr(r+1, n-r);
		string aux;
		for (int i=l; i<=r; i++){
			aux.push_back(s[i]);
		}
		cout << a + findGreater(aux) + c << endl;
	}
}