#include <bits/stdc++.h>
using namespace std;

const int N = 105;
int vet[N];

int main(){
	int n;
	scanf("%d", &n);
	int even = n/2;
	int odd = n-even;
	int ans = 0;
	for (int i=0; i<n; i++){
		scanf("%d", &vet[i]);
		if(vet[i] & 1) odd--;
		else even--;
		if(i != 0 && vet[i-1] != 0 && vet[i] != 0) ans += (vet[i]%2 != vet[i-1]%2);
	}
	for (int i=0; i<n; i++){
		if(vet[i] == 0){
			int l = i, r = i;
			while (r < n && vet[r] == 0) r++;
			r--;
			if((l == 0 || vet[l-1]%2 == 1) && (r == n-1 || vet[r+1]%2 == 1)) {
				if(odd >= r-l+1) {
					odd -= (r-l+1);
				}
				else if(odd != 0){
					ans++;
				}
				else {
					if(l != 0) ans++;
					if(r != n-1) ans++;
				}
			}
			else if((l == 0 || vet[l-1]%2 == 0) && (r == n-1 || vet[r+1]%2 == 0)) {
				if(even >= r-l+1) {
					even -= (r-l+1);
				}
				else if(even != 0){
					ans++;
				}
				else {
					if(l != 0) ans++;
					if(r != n-1) ans++;
				}
			}
			else ans++;
			i = r;
		}
	}
	printf("%d\n", ans);
}