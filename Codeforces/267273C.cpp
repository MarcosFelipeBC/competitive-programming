#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector < string > vet;
	for (int i=0; i<n; i++){
		string s;
		cin >> s;
		vet.push_back(s);	
	}
	reverse(vet.begin(), vet.end());
	for (int i=0; i<vet[0].size(); i++)
		if(vet[0][i] == '?') vet[0][i] = '9';

	for (int i=1; i<n; i++){
		if(vet[i].size() < vet[i+1].size()){
			for (int j=0; j<vet[i].size(); j++)
				if(vet[i][j] == '?') vet[i][j] = '9';
		}
		else {
			bool flag = false;
			for (int j=0; j<vet[i].size(); j++){
				if(vet[i][j] == '?'){
					if(flag) vet[i][j] = '9';
					else vet[i][j] = vet[i+1][j];
				}
				else {
					if(vet[i][j])
				}
			}
		}
	}
}