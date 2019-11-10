#include <bits/stdc++.h>
using namespace std;

const int N = 2005;
int vet[N];

int main(){
	int n;
	scanf("%d", &n);
	for (int i=0; i<n; i++){
		scanf("%d", &vet[i]);
	}
	sort(vet, vet+n);
	long long ans = 0LL;
	for (int i=0; i<n; i++){
		for (int j=i+1; j<n; j++){
			int lo = j+1, hi = n-1, idx = j;
			while (lo <= hi){
				int mid = (lo + hi) >> 1;
				if(vet[mid] < vet[i] + vet[j]){
					idx = mid;
					lo = mid+1;
				}
				else hi = mid-1;
			}
			ans += (long long)(idx - (j+1) +1);
		}
	}
	printf("%lld\n", ans);
}

