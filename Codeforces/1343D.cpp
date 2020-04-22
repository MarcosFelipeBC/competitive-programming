#include <bits/stdc++.h>
using namespace std;

const int N = 500105;
int vet[N];

int bit[N];

void update(int pos, int val){
	for (; pos < N; pos += (pos & (-pos)))
	{
		bit[pos] += val;
	}
}

int query(int pos){
	int ans = 0;
	for (; pos > 0; pos -= (pos & (-pos)))
	{
		ans += bit[pos];
	}
	return ans;
}

int main()
{
	int t;
	scanf("%d", &t);
	while (t-- > 0){
		int n, k;
		scanf("%d %d", &n, &k);
		for (int i=0; i<n; i++){
			scanf("%d", &vet[i]);
		}
		for (int i=0, j=n-1; i<n/2; i++, j--){
			int val = vet[i]+vet[j]+1;
			update(val, 1);
			int val2 = max(vet[i], vet[j])+k+1;
			update(val2, 1);
			update(k+k+1, -2);
			val = vet[i]+vet[j];
			update(val, -1);
			val2 = min(vet[i], vet[j])+1;
			update(val2, -1);
			update(2, 2);
		}
		int ans = 1e9;
		for (int i=2; i<=k+k; i++){
			ans = min(ans, query(i));
		}
		for (int i=0; i<=3*k; i++){
			bit[i] = 0;
		}
		printf("%d\n", ans);
	}
}