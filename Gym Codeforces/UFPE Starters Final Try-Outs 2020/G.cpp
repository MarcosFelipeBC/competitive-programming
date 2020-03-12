#include <bits/stdc++.h>
using namespace std;

map < string, int > problem;
map < string, int > pessoa;

int main(){
	int c, p, s;
	cin >> c >> p >> s;
	vector < string > vet;
	for (int i=0; i<c; i++){
		string str;
		cin >> str;
		vet.push_back(str);
	}
	for (int i=0; i<p; i++){
		string name;
		int points;
		cin >> name >> points;
		problem[name] = points;
	}
	for (int i=0; i<s; i++){
		string name, pro, ver;
		cin >> name >> pro >> ver;
		if(ver == "AC"){
			pessoa[name] += problem[pro];
		}
	}
	for (int i=0; i<vet.size(); i++){
		cout << vet[i] << ' ' << pessoa[vet[i]] << endl;
	}
}