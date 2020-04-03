#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t-- > 0)
	{
		int n;
		cin >> n;
		string str;
		cin >> str;
		string a(str.begin(), str.end()), b(str.begin(), str.end());
		bool one = false;
		for (int i=0; i<str.size(); i++){
			if(str[i] == '1') {
				if(one) b[i] = '1', a[i] = '0';
				else a[i] = '1', b[i] = '0';
				one = true;
			}
			else if(str[i] == '2') {
				if(one) b[i] = '2', a[i] = '0';
				else a[i] = b[i] = '1';
			}
			else a[i] = b[i] = '0';
		}
		cout << a << endl << b << endl;
	}
}