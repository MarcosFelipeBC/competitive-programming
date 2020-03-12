#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

string ans(string &s, int n){
	string resp;
	resp.resize(n);
	for (int i=0; i<s.size(); i++){
		for (int j=i; j<n; j+=s.size()){
			resp[j] = s[i];
		}
	}
	return resp;
}

void add(string &s, int k){
	for (int i=k-1; i>=0; i--){
		if(s[i] != '9'){
			s[i]++;
			break;
		}
		else s[i] = '0';
	}
}

int main(){
	int n, k;
	cin >> n >> k;
	string num;
	cin >> num;
	string str = num.substr(0, k);
	for (int i=0; i*k<n; i++){
		for (int j=i*k; j<min(n, i*k+k); j++){
			if(str[j-i*k] > num[j]){
				cout << n << endl;
				cout << ans(str, n) << endl;
				return 0;
			}
			else if(str[j-i*k] < num[j]){
				add(str, k);
				cout << n << endl;
				cout << ans(str, n) << endl;
				return 0;
			}
		}
	}
	cout << n << endl;
	cout << ans(str, n) << endl;
	return 0;

}