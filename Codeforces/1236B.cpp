#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;

long long fastPow(long long x, long long p)
{
	if(p == 1LL) return x;
	long long val = fastPow(x, p/2);
	val = (val%mod * val%mod)%mod;
	if(p & 1) val = (val%mod * x%mod)%mod;
	return val;
}

int main(){
	long long n, m;
	cin >> n >> m;
	long long b = (fastPow(2, m)%mod - 1 + mod)%mod;
	long long ans = fastPow(b, n);
	cout << ans << endl;

}