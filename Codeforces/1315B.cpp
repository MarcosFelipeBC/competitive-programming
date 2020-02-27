#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while (t-- > 0){
		int n, a, b, p;
		cin >> a >> b >> p;
		string s;
		cin >> s;
		n = s.size();
		int ans = n-1;
		bool flag = false;
		for (int i=n-1; i>0; i--){
			if(s[i-1] == 'A' && flag == false) 
			{
				flag = true;
				p -= a;
			}
			else if(flag == false)
			{
				flag = true;
				p -= b;
			}
			if(i-2 >= 0 && s[i-2] != s[i-1]) flag = false;
			if(p >= 0) ans = i-1;
		}
		cout << ans+1 << endl;
	}
}