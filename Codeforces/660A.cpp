#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	int last = -1;
	vector < int > vet;
	int cnt=0;
	for (int i=0; i<n; i++){
		int x;
		cin >> x;
		if(last != -1){
			if(__gcd(x, last) != 1) cnt++, vet.push_back(1);
		}
		last = x;
		vet.push_back(x);
	}
	cout << cnt << endl;
	for (int i=0; i<vet.size(); i++) {
		if(i) cout << ' ';
		cout << vet[i];
	}
	cout << endl;
	return 0;
}