#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while (t-- > 0){
		string str;
		cin >> str;
		reverse(str.begin(), str.end());
		for (int i=0; i<str.size(); i++){
			if(str[i] >= 'a' && str[i] <= 'z'){
				str[i] -= ('a' - 'A');
				if((int)str[i]+13 > 'Z'){
					str[i] = 'A' + ((int)str[i]+13 - 'Z' - 1);
				}
				else str[i]+=13;
			}
			else {
				str[i] -= ('A' - 'a');
				if((int)str[i]+13 > 'z'){
					str[i] = 'a' + ((int)str[i]+13 - 'z' - 1);
				}
				else str[i]+=13;
			}
		}
		cout << str << endl;
	}
}
