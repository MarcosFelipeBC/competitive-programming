#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while (t-- > 0){
		string str;
		cin >> str;
		stack < char > s;
		int ans = 0;
		for (int i=0; i<(int)str.size(); i++){
			if(str[i] == '>') {
				if(!s.empty() && s.top() == '<'){
					ans++;
					s.pop();
				}
			}
			else if(str[i] == '<') s.push('<');
		}
		cout << ans << endl;
	}
}
