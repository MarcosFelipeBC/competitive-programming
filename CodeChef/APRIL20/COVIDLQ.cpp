#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	scanf("%d", &t);
	while (t--){
		int n;
		scanf("%d", &n);
		int last = -1;
		bool ans = true;
		for (int i=0; i<n; i++){
			int x;
			scanf("%d", &x);
			if(last != -1 && x && i-last < 6) ans = false;
			if(x) last = i;
		}
		puts((ans) ? "YES" : "NO");
	}
}