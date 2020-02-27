#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	string str;
	cin >> str;
	bool ans = false;
	string aux = str;
	vector < int > resp;
 	for (int i=0; i<n-1; i++){
 		if(aux[i] == 'W') {
 			aux[i] = 'B';
 			aux[i+1] = (aux[i+1] == 'B') ? 'W' : 'B';
 		}
 	}
 	if(aux[n-1] == 'B') {
 		ans = true;
 		for (int i=0; i<n-1; i++){
 			if(str[i] == 'W') {
 				str[i] = 'B';
 				str[i+1] = (str[i+1] == 'B') ? 'W' : 'B';
 				resp.push_back(i+1);
 			}
 		}
 	}
 	else {
 		aux = str;
 		for (int i=0; i<n-1; i++){
	 		if(aux[i] == 'B') {
	 			aux[i] = 'W';
	 			aux[i+1] = (aux[i+1] == 'B') ? 'W' : 'B';
	 		}
	 	}
	 	if(aux[n-1] == 'W') {
	 		ans = true;
	 		for (int i=0; i<n-1; i++){
	 			if(str[i] == 'B') {
	 				str[i] = 'W';
	 				str[i+1] = (str[i+1] == 'B') ? 'W' : 'B';
	 				resp.push_back(i+1);
	 			}
	 		}
	 	}
 	}
 	if(!ans) cout << -1 << endl;
 	else {
 		cout << resp.size() << endl;
 		for (int i=0; i<resp.size(); i++){
 			cout << resp[i] << ' ';
 		}
 		cout << endl;
 	}
 }