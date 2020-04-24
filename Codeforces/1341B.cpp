#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
int vet[N], p[N];

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
		for (int i=1; i<n-1; i++){
			p[i] = p[i-1];
			if(vet[i] > vet[i-1] && vet[i] > vet[i+1]) p[i]++;
		}
		p[n-1] = p[n-2];
		int mx = -1, l = -1;
		for (int i=0; i+k-1<n; i++){
			if(mx < p[i+k-2] - p[i]){
				mx = p[i+k-2]-p[i];
				l = i+1;
			}
		}
		printf("%d %d\n", mx+1, l);
	}
}