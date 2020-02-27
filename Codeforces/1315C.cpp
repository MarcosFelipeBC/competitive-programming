#include <bits/stdc++.h>
using namespace std;

const int N = 505;
int a[N], b[N], vist[N];

int main(){
	int t;
	scanf("%d", &t);
	while (t-- > 0)
	{
		memset(vist, 0, sizeof vist);
		int n;
		scanf("%d", &n);
		for (int i=0; i<n; i++){
			scanf("%d", &b[i]);
			vist[b[i]]++;
		}

		for (int i=0; i<2*n; i+=2){
			 a[i] = b[i/2];
			 a[i+1] = -1;
		}
		int ans = 0;
		for (int i=1; i<2*n; i+=2){
			for (int j=a[i-1]+1; j<=2*n; j++){
				if(vist[j] == 0) {
					vist[j] = 1;
					a[i] = j;
					break;
				}
			}
			ans = min(ans, a[i]);
		}
		if(ans == -1) printf("-1\n");
		else {
			for (int i=0; i<2*n; i++){
				printf("%d ", a[i]);
			}
			printf("\n");
		}
	}
}