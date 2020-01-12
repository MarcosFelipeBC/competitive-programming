#include <bits/stdc++.h>
using namespace std;

const int N = 20;

long long dp[N][2][5];

long long solve(int pos, int less, int nonzero, string &num){	
	if(nonzero > 3) return 0;
	if(pos == num.size()) return (nonzero <= 3);
	long long &ans = dp[pos][less][nonzero];
	if(ans != -1) return ans;
	ans = 0;
	int limit = 9;
	if(!less) limit = num[pos] - 48; 
	for (int i=0; i<=limit; i++){
		ans += solve(pos+1, less | (i < limit), nonzero + (i != 0), num);
	}
	return ans;
}

int main(){
	int t;
	cin >> t;
	while (t-- > 0){
		string a, b;
		cin >> a >> b;
		memset(dp, -1, sizeof dp);
		long long ans = solve(0, 0, 0, b);
		memset(dp, -1, sizeof dp);
		ans -= solve(0, 0, 0, a);

		int cnt = 0;
		for (int i=0; i<a.size(); i++){
			if(a[i] >= '1' && a[i] <= '9') cnt++;
		}
		if(cnt <= 3) ans++;
		cout << ans << endl;
	}
}