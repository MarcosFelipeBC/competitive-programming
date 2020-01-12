#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	string str;
	cin >> str;
	int ans = 0;
	for (int i=0; i+2<n; i++){
		if(str.substr(i, 3) == "ABC") ans++;
	}
	cout << ans << endl;
}