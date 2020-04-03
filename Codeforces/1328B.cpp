#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t-- > 0)
	{
		int n, k;
		cin >> n >> k;
		int cnt = 0;
		string str;
		for (int i=0; i<n; i++) str.push_back('a');
		for  (int i=n-1; i>=1; i--){
			if(cnt + (n - i) >= k){
				int dif = k-cnt;
				str[i-1] = 'b';
				str[n-dif] = 'b';
				break;
			}
			cnt += (n-i);
		}
		cout << str << endl;
	}
}