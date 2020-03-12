#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 300005;
map < ll, int > mapa;
ll a[N], b[N];

int main(){
	int n;
	scanf("%d", &n);
	for (int i=0; i<n; i++){
		scanf("%lld", &a[i]);
		if(i) {
			a[i] += a[i-1];
		}
		mapa[a[i]] = i;
	}
	int m;
	scanf("%d", &m);
	int idx = 0;
	for (int i=0; i<m; i++){
		scanf("%lld", &b[i]);
		if(i) {
			b[i] += b[i-1];
		}
		if(mapa.count(b[i])){
			idx++;
		}
	}
	if(b[m-1] != a[n-1]) puts("-1");
	else printf("%d\n", idx);
}