//https://codeforces.com/gym/102346/problem/M

#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
int vet[N];

int main(){
	int n, c, t;
	scanf("%d %d %d", &n, &c, &t);
	int mx = 0;
	for (int i=0; i<n; i++){
		scanf("%d", &vet[i]);
		mx = max(mx, vet[i]);
	}
	int lo = mx, hi = 1000000000, ans;
	while (lo <= hi) {
		int mid = (lo + hi) >> 1;
		int sum = vet[0];
		int cnt = 1;
		for (int i=1; i<n; i++){
			if(sum+vet[i] > mid){
				sum = 0;
				cnt++;
			}
			sum += vet[i];
		}
		if(cnt <= c) {
			ans = mid;
			hi = mid-1;
		}
		else lo = mid+1;
	}
	printf("%d\n", ans/t + (ans%t != 0));
}
