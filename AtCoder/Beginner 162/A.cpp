#include <bits/stdc++.h>
using namespace std;

int main(){
	string str;
	cin >> str;
	bool ans = false;
	for (char ch : str){
		if(ch == '7') ans = true;
	}
	puts((ans) ? "Yes" : "No");
}