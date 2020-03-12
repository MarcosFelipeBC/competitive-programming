#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	scanf("%d", &t);
	while (t-- > 0){
		int n;
		scanf("%d", &n);
		long long par1 = 0, impar1 = 0;
		for (int i=0; i<n; i++){
			int x;
			scanf("%d", &x);
			if(x & 1) impar1++;
			else par1++;
		}
		int m;
		scanf("%d", &m);
		long long impar2=0, par2=0;
		for (int i=0; i<m; i++){
			int x;
			scanf("%d", &x);
			if(x&1) impar2++;
			else par2++;
		}
		printf("%lld\n", impar2*impar1 + par2*par1);
	}
}