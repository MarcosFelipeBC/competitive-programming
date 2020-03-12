#include <bits/stdc++.h>
using namespace std;

int mat[303][303];

int main()
{
	int n;
	cin >> n;
	int cnt = 1;
	for (int i=0; i<n; i++){
		if(i%2 == 0){
			for (int j=0; j<n; j++) mat[j][i] = cnt++;
		}
		else {
			for (int j=n-1; j>=0; j--) mat[j][i] = cnt++;
		}
	}
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			cout << mat[i][j] << ' ';
		}
		cout << endl;
	}	
}