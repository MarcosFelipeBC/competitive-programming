#include <bits/stdc++.h>
using namespace std;

bool prime(int p)
{
	for (int i=2; i*i < p; i++)
		if(p%i == 0) return false;
	return true;
}

int main(){
	int n;
	scanf("%d", &n);
	if (!prime(n+15)) printf("%d %d\n", n+15, 15);
	else printf("%d %d\n", n+16, 16);
}