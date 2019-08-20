//https://codeforces.com/problemset/problem/1204/A

#include <bits/stdc++.h>
using namespace std;

int main(){
	string str;
	cin >> str;
	if(str == "0") cout << 0 << endl;
	else {
		reverse(str.begin(), str.end());
		int ans = 0, cont=0;
		for (int i=0; i<str.size(); i++){
			if(str[i] == '1') cont++;
		}
		for (int i=0; i<str.size(); i+=2){
			ans++;
			if(i == str.size()-1){
				if(str[i] == '1'){
					if(cont == 1) ans--;
				}
			}
		}
		cout << ans << endl;
	}
}
