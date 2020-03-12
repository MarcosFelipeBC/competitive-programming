#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	long double ans = 0;
	for (int i=0; i<n; i++){
		ans += (1.0/(long double)(n-i));
	}
	printf("%.8Lf", ans);
}