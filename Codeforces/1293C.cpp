#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
int mat[3][N];

int main(){
	int n, q;
	scanf("%d %d", &n, &q);
	int sum = 0;
	for (int i=0; i<q; i++){
		int x, y;
		scanf("%d %d", &x, &y);
		mat[x][y] ^= 1;
 		if(x == 1){
 			if(mat[x][y] == 1){
 				if(mat[2][y]) sum++;
 				if(y-1 >= 1 && mat[2][y-1]) sum++;
 				if(y+1 <= n && mat[2][y+1]) sum++;
 			}
 			else {
 				if(mat[2][y]) sum--;
 				if(y-1 >= 1 && mat[2][y-1]) sum--;
 				if(y+1 <= n && mat[2][y+1]) sum--;
 			}
 		}
 		else {
 			if(mat[x][y] == 1){
 				if(mat[1][y]) sum++;
 				if(y-1 >= 1 && mat[1][y-1]) sum++;
 				if(y+1 <= n && mat[1][y+1]) sum++;
 			}
 			else {
 				if(mat[1][y]) sum--;
 				if(y-1 >= 1 && mat[1][y-1]) sum--;
 				if(y+1 <= n && mat[1][y+1]) sum--;
 			}
 		}
 		if(sum == 0 && mat[1][1] == 0 && mat[2][n] == 0) puts("Yes");
 		else puts("No");
	}
}