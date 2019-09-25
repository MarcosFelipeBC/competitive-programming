//https://codeforces.com/contest/1023/problem/C

#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, k;
	cin >> n >> k;
	string str;
	cin >> str;
	string ans;
	int qtdOpen = 0, qtdClose = 0;
	for (int i=0; i<n; i++){
		if(str[i] == '('){
			if(qtdOpen < k/2) {
				qtdOpen++;
				ans.push_back('(');
			}
		}
		else {
			if(qtdClose < k/2 && qtdClose+1 <= qtdOpen){
				qtdClose++;
				ans.push_back(')');
			}
		}
	}
	cout << ans << endl;
}
