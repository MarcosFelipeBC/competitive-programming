#include <bits/stdc++.h>
using namespace std;

int n, h, l, r;
const int N = 2020;
int vet[N];
int dp[N][N];

int solve(int pos, int now)
{
	if(pos == n) return 0;
	int &ans = dp[pos][now];
	if(ans != -1) return ans;
	int nxt = (vet[pos]+now)%h;
	int nxt2 = ((vet[pos]-1)+now)%h;
	ans = max(ans, solve(pos+1, nxt) + (nxt >= l && nxt <= r));
	ans = max(ans, solve(pos+1, nxt2) + (nxt2 >= l && nxt2 <= r));
	return ans;
}

int main(){
	cin >> n >> h >> l >> r;
	for (int i=0; i<n; i++) cin >> vet[i];
	memset(dp, -1, sizeof dp);
	cout << solve(0, 0) << endl;
}