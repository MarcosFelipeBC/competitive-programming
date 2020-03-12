//https://codeforces.com/gym/101810/problem/I

#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	scanf("%d", &t);
	while (t-- > 0){
		int n, x;
		scanf("%d %d", &x, &n);
		int resto = x%n;
		vector < int > ans;
		for (int i=0; i<n; i++){
			if(x/n + (resto != 0) != 0) ans.push_back(x/n + (resto != 0));
			if(resto > 0) resto--;
		}
		if(ans.size() != n){
			printf("-1\n");
			continue ;
		}
		reverse(ans.begin(), ans.end());
		for(int i=0; i<n; i++){
			if(i) printf(" ");
			printf("%d", ans[i]);
		}
		puts("");
	}
}
