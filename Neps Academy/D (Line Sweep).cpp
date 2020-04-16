//https://neps.academy/contest/215/problem/682

#include <bits/stdc++.h>
using namespace std;

map < int, int> mapa;

int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	vector < int > vet;
	for (int i=0; i<n; i++){
		int xa, ya, xb, yb;
		scanf("%d %d %d %d", &xa, &ya, &xa, &yb);
		mapa[ya] = xb - xa;
		mapa[yb] = -(xb - xa);
		vet.push_back(yb);
		vet.push_back(ya);
	}
	sort(vet.begin(), vet.end());
	long long sum = 0LL, ans = -1;
	for (int i=0; i<n-1; i++){
		int y = vet[i], nxty = vet[i+1];
		int mult = mapa[y];
		if(sum + mapa[y] * (nxty - y) < k){
			sum += mult * (nxty - y);
		}
		else {
			int lo = 1, hi = nxty - y, resp = -1;
			while (lo <= hi) {
				int mid = (lo + hi) >> 1;
				if(sum + mult * mid >= k) {
					resp = mid;
					hi = mid-1;
				}
				else lo = mid+1;
			}
			if(resp != -1){
				ans = resp;
				break;
			}
		}
	}
	if(ans != -1) printf("%lld\n", ans);
	else {
		printf("PERDAO MEU REI\n");
	}
	
}