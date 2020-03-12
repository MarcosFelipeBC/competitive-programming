#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	string str;
	cin >> str;
	int ans = 0;
	for (int c = 'z'; c >= 'a';)
	{
		bool flag = true;
		for (int i=0; i<str.size(); i++)
		{
			if(str[i] == c) 
			{
				if((i-1>=0 && str[i-1]+1 == str[i]) || (i+1 < str.size() && str[i+1]+1 == str[i]))
				{
					ans++;
					str.erase(str.begin()+i);
					flag = false;
					break;
				}
			}
			
		}
		if(flag) c--;
	}
	cout << ans << endl;
}
