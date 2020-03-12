#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	for (int i=0; i<n; i++){
		string str;
		cin >> str;
		str.push_back('R');
		int last = -1, ans = 0;
		for (int j=0; j<str.size(); j++){
			if(str[j] == 'R'){
				ans = max(ans, j - last);
				last = j;
			}
		}
		cout << ans << endl;
	}
}