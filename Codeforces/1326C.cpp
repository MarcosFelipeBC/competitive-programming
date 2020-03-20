#include <bits/stdc++.h>
#define mod 998244353
using namespace std;

const int N = 200005;
int p[N];

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i=0; i<n; i++){
		scanf("%d", &p[i]);
	}
	vector < int > aux;
	long long sum = 0LL;
	for (int i=0; i<n; i++){
		if(p[i] > n-k) aux.push_back(i), sum += p[i];
	}
	long long ans = 1LL;
	for (int i=1; i<aux.size(); i++){
		ans = (ans * ((long long)(aux[i] - aux[i-1]))%mod)%mod;
	}
	printf("%lld %lld\n", sum, ans);
}