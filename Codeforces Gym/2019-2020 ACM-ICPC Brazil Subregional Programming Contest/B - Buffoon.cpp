//https://codeforces.com/gym/102346/problem/B

#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	int x;
	scanf("%d", &x);
	bool ans = true;
	for (int i=0; i<n-1; i++){
		int y;
		scanf("%d", &y);
		if(x < y) ans = false;
	}
	puts((ans) ? "S" : "N");
}
