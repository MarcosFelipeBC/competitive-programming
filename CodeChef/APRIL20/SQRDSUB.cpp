#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
int vet[N];

int main()
{
	int t;
	scanf("%d", &t);
	while (t-- > 0){
		int n;
		scanf("%d", &n);	
		for (int i=0; i<n; i++){
			scanf("%d", &vet[i]);
			if(vet[i] & 1) vet[i] = 0;
			else if(vet[i] %4 == 0) vet[i] = 2;
			else vet[i] = 1;
		}
		long long ans = ((long long)(n+1) * n/2LL);
		unordered_map < int, int > mp;
		mp[0] = 1;
		int sum = 0;
		for (int i=0; i<n; i++){
			sum += vet[i];
			ans -= mp[1 - sum];
			mp[-sum]++;
		}
		printf("%lld\n", ans);
	}
}