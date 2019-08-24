//https://codeforces.com/gym/102302/problem/D

#include <bits/stdc++.h>
using namespace std;

int main(){
	string str, s;
	cin >> str >> s;
	int p = 0;
	for (char c : str){
		if(c == s[p]){
			p++;
		}
	}
	puts((p == s.size()) ? "YES" : "NO");
}
