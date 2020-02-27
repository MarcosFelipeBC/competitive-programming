#include <bits/stdc++.h>
using namespace std;

const int N = 500005;

int main(){
	int t;
	cin >> t;
	while (t-- > 0){
		string a, b, c;
		cin >> a >> b >> c;
		int n = a.size();
		bool flag = true;
		for (int i=0; i<n; i++){
			if(c[i] == a[i] || c[i] == b[i]) continue ;
			flag = false;
		}
		cout << ((flag) ? "YES" :"NO") << endl;
	}
}