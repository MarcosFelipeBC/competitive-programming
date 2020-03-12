#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
int wood[N], ans[N];

int main(){
	int n, m, d;
	scanf("%d %d %d", &n, &m, &d);
	int sum = 0;
	for (int i=0; i<m; i++){
		scanf("%d", &wood[i]);
		sum += wood[i];
	}
	int pos = 0;
	for (int i=0; i<m; i++){
		sum -= wood[i];
		for (int j=d; j>=1; j--)
		{
			if(pos + j + wood[i]-1 + sum <= n){
				for (int k = pos+j; k < pos+j+wood[i]; k++) ans[k] = i+1;
				pos += (j+wood[i]-1);
				break;
			}
		}
	}
	if(pos + d < n+1) puts("NO");
	else {
		puts("YES");
		for (int i=1; i<=n; i++){
			printf("%d ", ans[i]);
		}
		puts("");
	}
}