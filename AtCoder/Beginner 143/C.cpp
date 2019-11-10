#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	string str;
	cin >> str;
	str.push_back('*');
	int ans = 0;
	for (int i=0; i<n; i++){
		if(str[i+1] != str[i]) ans++;
	}
	cout << ans << endl;
}
