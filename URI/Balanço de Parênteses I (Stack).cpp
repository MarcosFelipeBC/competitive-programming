//https://www.urionlinejudge.com.br/judge/pt/problems/view/1068
#include <bits/stdc++.h>
using namespace std;

int main(){
	string str;
	while (cin >> str){
		stack < char > s;
		bool ans = true;
		for (int i=0; i<str.size(); i++){
			if(str[i] == ')'){
				if(!s.empty() && s.top() == '(') s.pop();
				else {
					ans = false;
					break;
				}
			}
			else if(str[i] == '(') s.push('(');
		}
		if (!s.empty()) s.pop(), ans = false;
		puts((ans) ? "correct" : "incorrect");
	}
}
