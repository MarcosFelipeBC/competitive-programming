#include <bits/stdc++.h>
using namespace std;

const int N = 500005;

int main()
{
	int t;
	cin >> t;
	while (t-- > 0){
		string str;
		cin >> str;
		int ans = 0;
		int flag = 0, now = 0;
		for (int i=0; i<str.size(); i++){
			if(str[i] == '1'){
				if(flag){
					ans += now;
					now = 0;
				}
				flag = 1;
			}
			else {
				if(flag){
					now++;
				}
			}
		}
		cout << ans << endl;
	}
}