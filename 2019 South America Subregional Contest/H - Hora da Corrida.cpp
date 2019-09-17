#include <bits/stdc++.h>
using namespace std;

int main(){
	int v, n;
	scanf("%d %d", &v, &n);
	for (int i=1; i<10; i++){
		if(i != 1) printf(" ");
		printf("%d", (int)ceil((n*v)*i/10.0));
	}
	printf("\n");
}
