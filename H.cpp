//https://codeforces.com/gym/102302/problem/H

#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;

typedef long long ll;
const int N = 9;

struct matrix {
	ll mat[N][N];
	matrix(){
		memset(mat, 0, sizeof mat);
	}
	matrix operator * (matrix aux){
		matrix ans;
		for (int i=0; i<N; i++){
			for (int j=0; j<N; j++){
				for (int k=0; k<N; k++){
					ans.mat[i][j] = (ans.mat[i][j]%mod + (mat[i][k]%mod * aux.mat[k][j]%mod)%mod)%mod;
				}
			}
		}
		return ans;
	}
};

matrix expo(long long n, matrix base){
	if(n == 1) return base;
	matrix ans = expo(n/2, base);
	ans = ans * ans;
	if(n & 1) ans = ans * base;
	return ans;
}

int main(){
	ll n;
	scanf("%lld", &n);
	int vet[N] = {3, 1, 1, 3, 2, 1, 3, 3, 3};
	matrix mat;
	mat.mat[0][0] = mat.mat[0][3] = mat.mat[0][6] = 1;
	mat.mat[1][0] = 1;
	mat.mat[2][0] = 1;
	mat.mat[3][1] = mat.mat[3][4] = mat.mat[3][7] = 1;
	mat.mat[4][1] = mat.mat[4][4] = 1;
	mat.mat[5][1] = 1;
	mat.mat[6][2] = mat.mat[6][5] = mat.mat[6][8] = 1;
	mat.mat[7][2] = mat.mat[7][5] = mat.mat[7][8] = 1;
	mat.mat[8][2] = mat.mat[8][5] = mat.mat[8][8] = 1;
	long long ans = 0LL;
	if(n == 3) ans = 20;
	else {
		mat = expo(n-3, mat);
		for (int i=0; i<N; i++){
			for (int k=0; k<N; k++){
				ans = (ans%mod + (mat.mat[i][k]%mod * vet[k]%mod)%mod)%mod;
			}
		}
	}
	printf("%lld\n", ans);
}
