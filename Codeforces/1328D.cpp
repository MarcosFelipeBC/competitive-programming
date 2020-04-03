#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
int color[N], vet[N];

int main()
{
	int q;
	scanf("%d", &q);
	while (q-- > 0)
	{
		int n;
		scanf("%d", &n);
		bool hasAdjacentEqual = false;
		bool allEqual = true;
		for (int i=0; i<n; i++) scanf("%d", &vet[i]);
		for (int i=0; i<n; i++) {
			int prev = i-1;
			if(prev < 0) prev = n-1;
			if(vet[i] == vet[prev]) hasAdjacentEqual = true;
			else allEqual = false;
		}
		if(allEqual)
		{
			printf("1\n");
			for (int i=0; i<n; i++){
				if(i) printf(" ");
				printf("1");
			}
			printf("\n");
		}
		else if((n & 1) == 0)
		{
			printf("2\n");
			for (int i=0; i<n; i++){
				if(i) printf(" ");
				printf("%d", (i&1)+1);
			}
			printf("\n");
		}
		else {
			if(hasAdjacentEqual){
				printf("2\n");
				bool flag = false;
				for (int i=0; i<n; i++){
					int prev = i-1;
					if(prev < 0) prev = n-1;
					if(i) printf(" ");
					if(i && vet[i] == vet[prev]){
						flag = true;
						printf("%d", ((i+1)&1) + 1);
					}
					else {
						if(!flag) printf("%d", (i&1)+1);
						else printf("%d", ((i+1)&1)+1);
					}
				}
				printf("\n");
			}
			else {
				printf("3\n");
				for (int i=0; i<n-1; i++){
					if(i) printf(" ");
					printf("%d", (i&1)+1);
				}
				printf(" 3");
				printf("\n");
			}
		}
	}
}