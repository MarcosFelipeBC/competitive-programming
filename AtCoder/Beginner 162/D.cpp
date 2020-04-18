#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	string str;
	cin >> str;
	int r = 0, g = 0, b = 0;
	for (char ch : str){
		if(ch == 'R') r++;
		else if(ch == 'G') g++;
		else b++;
	}
	long long ans = (long long)r * (long long)g * (long long)b;
	for (int dist = 1; dist < n; dist++){
		for (int i=0; i+dist+dist < n; i++){
			int j = i+dist;
			int k = j+dist;
			if(str[i] != str[j] && str[i] != str[k] && str[k] != str[j]) ans--;
		}
	}
	cout << ans << endl;
}