#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	string s;
	cin >> s;
	stack < char > p;
	int open = 0, close = 0, ans = 0;
	for (int i=0; i<n; i++){
		if(s[i] == '(') open++, p.push('(');
		else {
			close++;
			if(!p.empty() && p.top() == '(') p.pop();
			else p.push(')');
		}
		if(open == close){
			if(!p.empty()) {
				ans += (open + close);	
			}
			open = 0, close = 0;
			while (!p.empty()) p.pop();
		}
	}
	if(open + close != 0) ans = -1;
	cout << ans << endl;
}