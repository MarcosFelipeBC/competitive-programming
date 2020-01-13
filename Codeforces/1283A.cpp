#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	scanf("%d", &t);
	while (t-- > 0){
		int h, m;
		scanf("%d %d", &h, &m);
		int ans = (23 - h) * 60 + 60 - m;
		printf("%d\n", ans);
	}
}