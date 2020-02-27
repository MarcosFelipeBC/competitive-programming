#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
int mat[N][N];

int main(){
	int n, a, b;
	cin >> n >> a >> b;
	if(a != 1 && b != 1){
		cout << "NO" << endl;
		return 0;
	}
	else if(a == 1 && b == 1)
	{
		if(n == 2 || n == 3){
			cout << "NO" << endl;
			return 0;
		}
		cout << "YES" << endl;
		for (int i=1; i<n-1; i++){
			mat[0][i] = mat[i][0] = 1;
		}		
		if(n != 1) mat[n-2][n-1] = mat[n-1][n-2] = 1;
		for (int i=0; i<n; i++){
			for (int j=0; j<n; j++){
				cout << mat[i][j];
			}
			cout << endl;
		}
		return 0;
	}
	cout << "YES" << endl;
	int x = max(a, b);
	for (int i=x-1; i<n; i++){
		for (int j=x-1; j<n; j++)
		{
			if(i != j) mat[i][j] = 1, mat[j][i] = 1;
		}
	}
	if(x == b){
		for (int i=0; i<n; i++)
		{
			for (int j=0; j<n; j++)
			{
				if(i != j) mat[i][j] = 1-mat[i][j];
			}
		}
	}
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			cout << mat[i][j];
		}
		cout << endl;
	}
}