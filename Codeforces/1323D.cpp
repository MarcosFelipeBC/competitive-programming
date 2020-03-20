#include <bits/stdc++.h>
using namespace std;

const int N = 400005;
const int L = 25;
int vet[N], n;

int solve(int k)
{
	vector < int > aux;
	for (int i=0; i<n; i++) aux.push_back(vet[i] % (1 << (k+1)));
	sort(aux.begin(), aux.end());
	long long qtd = 0LL;
	for (int i=0; i<n; i++){
		int l = lower_bound(aux.begin(), aux.end(), (1 << k) - aux[i]) - aux.begin();
		int r = upper_bound(aux.begin(), aux.end(), ((1 << (k+1))-1) - aux[i]) - aux.begin();
		if(r-l > 0) qtd += (long long)(r - l);
		if(i >= l && i < r) qtd--;
		l = lower_bound(aux.begin(), aux.end(), (1 << (k+1)) + (1 << k) - aux[i]) - aux.begin();
		r = upper_bound(aux.begin(), aux.end(), ((1 << (k+2))-2) - aux[i]) - aux.begin();
		if(r-l > 0) qtd += (long long)(r - l);
		if(i >= l && i < r) qtd--;
	}
	qtd /= 2LL;
	return (qtd & (1LL));
}	

int main()
{
	scanf("%d", &n);
	for (int i=0; i<n; i++){
		scanf("%d", &vet[i]);
	}
	int ans = 0;
	for (int i=0; i<L; i++){
		ans ^= (solve(i) << i);
	}
	printf("%d\n", ans);
}