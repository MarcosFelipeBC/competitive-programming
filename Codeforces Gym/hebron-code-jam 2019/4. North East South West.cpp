//https://codeforces.com/gym/102157/problem/4

#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	string ans = "north";
	for (int i=0; i<n; i++){
		string str;
		cin >> str;
		if(str == "left") {
			if(ans == "north") ans = "west";
			else if(ans == "east") ans = "north";
			else if(ans == "south") ans = "east";
			else ans = "south";
		}
		else if(str == "right") {
			if(ans == "north") ans = "east";
			else if(ans == "east") ans = "south";
			else if(ans == "south") ans = "west";
			else ans = "north";
		}
		else {
			if(ans == "north") ans = "south";
			else if(ans == "east") ans = "west";
			else if(ans == "south") ans = "north";
			else ans = "east";
		}
	}
	cout << ans << endl;
}
