//https://codeforces.com/problemset/problem/1220/C

#include <bits/stdc++.h>
using namespace std;

int main(){
	string str;
	cin >> str;
	char c = 'z'+1;
	for (int i=0; i<(int)str.size(); i++){
		if(c >= str[i]){
			puts("Mike");
		}
		else puts("Ann");
		c = min(c, str[i]);
	}
}
