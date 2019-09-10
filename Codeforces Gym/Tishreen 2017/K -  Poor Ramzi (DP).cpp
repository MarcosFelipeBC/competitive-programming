//https://codeforces.com/gym/101915/problem/K

#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;

typedef long long ll;
ll dp[55][55];

ll solve(int l, int r, const string &str){
	if(l > r || l == r) return 1LL;
	ll &ans = dp[l][r];
	if(ans != -1) return ans;
	ans = 1LL;
	int sumL = 0;
	for (int i=l; i<r; i++){
		sumL += (str[i] == '1');
		int sumR = 0;
		for (int j = r; j > i; j--){
			sumR += (str[j] == '1');
			if(sumL == sumR){
				ans = (ans + solve(i+1, j-1, str))%mod;
			}
			
		}
	}
	return ans;
}

int main(){
	int t;
	cin >> t;
	while (t-- > 0){
		string str;
		cin >> str;
		memset(dp, -1, sizeof dp);
		cout << solve(0, str.size()-1, str) << endl;
	}
}
