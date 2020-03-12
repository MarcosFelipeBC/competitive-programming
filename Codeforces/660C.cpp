#include <bits/stdc++.h>
using namespace std;

const int N = 300005;
int vet[N], aux[N];

int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i=0; i<n; i++){
		scanf("%d", &vet[i]);
		aux[i] = vet[i];
		if(i) vet[i] += vet[i-1];
	}
	int mx = -1, pos_mx = -1;
	for (int i=0; i<n; i++){
		int lo = i, hi = n-1, resp = i-1;
		while (lo <= hi){
			int mid = (lo + hi) >> 1;
			if((mid - i + 1) - (vet[mid] - ((i != 0) ? vet[i-1] : 0)) <= k){
				lo = mid+1;
				resp = mid;
			}
			else hi = mid-1;
		}
		if(resp - i + 1 > mx){
			mx = resp - i + 1;
			pos_mx = i;
		}
	}
	int ans = 0;
	while (pos_mx < n && k > 0){
		if(aux[pos_mx] == 0) {
			k--, aux[pos_mx] = 1;
		}
		pos_mx++;
	}
	printf("%d\n", mx);
	for (int i=0; i<n; i++){
		if(i) printf(" ");
		printf("%d", aux[i]);
	}
	puts("");
}