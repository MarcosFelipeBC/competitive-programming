//https://codeforces.com/contest/1245/problem/B

#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while (t-- > 0){
		int n;
		cin >> n;
		int a, b, c;
		cin >> a >> b >> c;
		string str;
		cin >> str;
		int r = 0, p = 0, s = 0;
		for (int i=0; i<n; i++){
			if(str[i] == 'R') r++;
			else if(str[i] == 'P') p++;
			else s++;
		}
		if(min(b, r) + min(c, p) + min(a, s) < n/2 + (n%2)){
			puts("NO");
			continue ;
		}
		else {
			puts("YES");
			string ans = str;
			for (int i=0; i<n; i++){
				if(str[i] == 'R'){
					if(b){
						ans[i] = 'P';
						b--;
					}
					else ans[i] = '?';
				}
				if(str[i] == 'P'){
					if(c){
						ans[i] = 'S';
						c--;
					}
					else ans[i] = '?';
				}
				if(str[i] == 'S'){
					if(a){
						ans[i] = 'R';
						a--;
					}
					else ans[i] = '?';
				}
			}
			for (int i=0; i<n; i++){
				if(ans[i] == '?'){
					if(a > 0) {
						ans[i] = 'R';
						a--;
					}
					else if(b > 0) {
						ans[i] = 'P';
						b--;
					}
					else {
						ans[i] = 'S';
						c--;
					}
				}
			}
			cout << ans << endl;
		}
	}
}
