#include <bits/stdc++.h>
using namespace std;

int main()
{
	int x;
	scanf("%d", &x);
	if(x < 1) puts("E");
	else if(x < 36) puts("D");
	else if(x < 61) puts("C");
	else if(x < 86) puts("B");
	else puts("A");
}