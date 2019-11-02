//https://codeforces.com/contest/1245/problem/C

#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;

const int N = 100005;
long long dp[N];
int n;
string str;

long long back(int pos){
	if(pos == n) return 1;
	long long &ans = dp[pos];
	if(ans != -1LL) return dp[pos];
	ans = 0LL;
	if(pos+1 != n && (str[pos] == 'n' && str[pos+1] == 'n')){
		ans += back(pos+2);
		ans %= mod;
	}
	if(pos+1 != n && (str[pos] == 'u' && str[pos+1] == 'u')){
		ans += back(pos+2);
		ans %= mod;
	}
	ans += back(pos+1);
	ans %= mod;
	return ans;
}

int main(){
	cin >> str;
	memset(dp, -1, sizeof dp);
	n = str.size();
	bool flag = true;
	for (int i=0; i<n; i++){
		if(str[i] == 'm' || str[i] == 'w') flag = false;
	}
	if(!flag) puts("0");
	else cout << back(0)%mod << endl;
}
