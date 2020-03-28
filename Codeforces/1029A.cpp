#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	string ans = "", aux = s;
	for (int i=1; i<n; i++){
		if(s.substr(i, n-i) == s.substr(0, n-i)) {
			aux = s.substr(n-i, n - (n-i));
			break;
		}
	}
	ans = s;
	for (int i=1; i<k; i++) ans += aux;
	cout << ans << endl;
}