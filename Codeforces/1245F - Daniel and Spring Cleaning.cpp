//https://codeforces.com/contest/1245/problem/F

#include <bits/stdc++.h>
using namespace std;

const int L = 31;
long long dp[L][2][2][2][2][2][2];
int b, a;

long long back(int pos, int val1, int val2, int less1, int less2, int great1, int great2);

long long chama00(int pos, int val1, int val2, int less1, int less2, int great1, int great2){
	if((a & (1 << (pos-1))) != 0 && (great1 == 0 || great2 == 0)) return 0LL;
	int nless1 = less1, nless2 = less2;
	if((b & (1 << (pos-1))) != 0) nless1 = nless2 = 1;
	return back(pos-1, 0, 0, nless1, nless2, great1, great2);
}

long long chama01(int pos, int val1, int val2, int less1, int less2, int great1, int great2){
	int nless1 = less1, ngreat2 = great2;
	if((a & (1 << (pos-1))) != 0 && great1 == 0) return 0LL;
	if((a & (1 << (pos-1))) == 0) ngreat2 = 1;
	if((b & (1 << (pos-1))) == 0 && less2 == 0) return 0LL;
	if((b & (1 << (pos-1))) != 0) nless1 = 1;
	return back(pos-1, 0, 1, nless1, less2, great1, ngreat2);
	
}

long long chama10(int pos, int val1, int val2, int less1, int less2, int great1, int great2){
	int nless2 = less2, ngreat1 = great1;
	if((a & (1 << (pos-1))) != 0 && great2 == 0) return 0LL;
	if((a & (1 << (pos-1))) == 0) ngreat1 = 1;
	if((b & (1 << (pos-1))) == 0 && less1 == 0) return 0LL;
	if((b & (1 << (pos-1))) != 0) nless2 = 1;
	return back(pos-1, 1, 0, less1, nless2, ngreat1, great2);
}

long long chama11(int pos, int val1, int val2, int less1, int less2, int great1, int great2){
	int ngreat1 = great1, ngreat2 = great2;
	if((b & (1 << (pos-1))) == 0 && (less1 == 0 || less2 == 0)) return 0LL;
	if((a & (1 << (pos-1))) == 0) ngreat1 = ngreat2 = 1;
	return back(pos-1, 1, 1, less1, less2, ngreat1, ngreat2);
}

long long back(int pos, int val1, int val2, int less1, int less2, int great1, int great2){
	if(pos == 0) return 1LL;
	long long &ans = dp[pos][val1][val2][less1][less2][great1][great2];
	if(ans != -1LL) return ans;
	ans = 0LL;
	ans += chama01(pos, val1, val2, less1, less2, great1, great2);
	ans += chama10(pos, val1, val2, less1, less2, great1, great2);
	ans += chama00(pos, val1, val2, less1, less2, great1, great2);
	return ans;
}

int main(){
	int t;
	scanf("%d", &t);
	while (t-->0){
		scanf("%d %d", &a, &b);
		memset(dp, -1LL, sizeof dp);
		printf("%lld\n", back(30, 0, 0, 0, 0, 0, 0));
	}
}
