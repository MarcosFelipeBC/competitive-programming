#include <bits/stdc++.h>
using namespace std;

const int N = 500005;

int main()
{
	int n;
	cin >> n;
	for (int i=0; i<n; i++){
		string str;
		cin >> str;
		if(str.size() >= 2) {
			if(str.substr(str.size()-2, 2) == "po"){
				cout << "FILIPINO\n";
				continue ;
			}
		}
		if(str.size() >= 4) {
			if(str.substr(str.size()-4, 4) == "desu" || str.substr(str.size()-4, 4) == "masu"){
				cout << "JAPANESE\n";
				continue ;
			}
		}
		if(str.size() >= 5){
			if(str.substr(str.size()-5, 5) == "mnida"){
				cout << "KOREAN\n";
				continue ;
			}
		}
	}
}