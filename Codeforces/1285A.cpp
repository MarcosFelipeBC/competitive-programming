#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	string str;
	cin >> str;
	int a = 0, b = 0;
	for (int i=0; i<n; i++){
		if(str[i] == 'L') a++;
		else b++;
	}
	cout << a + b + 1 << endl;
}