#include <bits/stdc++.h>
using namespace std;

int main(){
	long long n;
	scanf("%lld", &n);
	if(n == 3) printf("1\n");
	else printf("%lld", n*((n-1)/2) - ((n%3 == 0) ? n*2/3 : 0)); 	
}