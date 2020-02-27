#include <bits/stdc++.h>
using namespace std;

const int N = 2005;
int a[N], b[N];

int solve(vector < int >&vet, int m, int n){
	int x;
	if(vet[0] <= b[0]) x = b[0] - vet[0];
	else x = b[0] + m - vet[0];
	for (int i=0; i<n; i++){
		vet[i] += x;
		vet[i] %= m;
	}
	sort(vet.begin(), vet.end());
	for (int i=0; i<n; i++) if(vet[i] != b[i]) return -1;
	return x;
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	for (int i=0; i<n; i++){
		scanf("%d", &b[i]);
	}	
	sort(b, b+n);
	long long resp = 1000000000000;
	for (int i=0; i<n; i++){
		vector < int > vet;
		for (int j=i; j<n; j++) vet.push_back(a[j]);
		for (int j=0; j<i; j++) vet.push_back(a[j]);
		int ans = solve(vet, m, n);
		if(ans != -1) {
			resp = min((long long)ans, resp);
		}
	}
	printf("%d", resp);
}