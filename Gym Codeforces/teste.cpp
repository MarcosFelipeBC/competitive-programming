#include <bits/stdc++.h>
using namespace std;

int main()
{
	while (1)
	{
		string str;
		cin >> str;
		int sum = 0;
		for (int i=0; i<str.size(); i++){
			sum += str[i];
		}
		cout << sum%2 << endl;
	}
}