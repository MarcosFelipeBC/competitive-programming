#include <bits/stdc++.h>
using namespace std;

const int N = 2005;
int ans[N];

int dist(int i, int j, const int &x, const int &y)
{
	if(j <= x || i >= y) return j-i;
	if(i >= x && j <= y) {
		int resp = j-i;
		resp = min(resp, i-x + y-j + 1);
		return resp;
	}
	if(i <= x && j >= y) return x-i + j-y + 1;
	if(i >= x) {
		int resp = j-y;
		resp += min(y-i, i-x + 1);
		return resp;
	}
	if(j <= y){
		int resp = x-i;
		resp += min(j-x, y-j + 1);
		return resp;
	}
}

int main()
{
	int n, x, y;
	scanf("%d %d %d", &n, &x, &y);
	for (int i=1; i<=n-1; i++){
		for (int j=i+1; j<=n; j++){
			ans[dist(i, j, x, y)]++;
		}
	}
	for (int i=1; i<n; i++){
		cout << ans[i] << endl;
	}
}