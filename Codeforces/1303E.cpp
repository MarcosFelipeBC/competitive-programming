#include <bits/stdc++.h>
using namespace std;

const int N = 404;

int last[N], dp[N][N], nxt[N][N], n;
string base, frank;

int solve(int posa, int posb, const int enda)
{
	if(posa == enda && posb == base.size()) return 1;
	int &ans = dp[posa][posb];
	if(ans != -1) return ans;
	ans = 0;
	int pos = max(posa, posb);
	if(posa != enda && nxt[pos][frank[posa]] != -1) ans |= (solve(posa+1, posb, enda));
	if(posb != base.size() && nxt[pos][frank[posb]] != -1) ans |= (solve(posa, posb+1, enda));
	return ans;
}

int main(){
	int t;
	cin >> t;
	while (t-- > 0)
	{
		cin >> base >> frank;
		n = base.size();
		memset(last, -1, sizeof last);
		for (int i=n-1; i>=0; i--){
			for (int j='a'; j<='z'; j++)
			{
				nxt[i][j] = last[j];
			}
			last[base[i]] = i;
		}
		if(base == frank) {
			cout << "YES\n";
			continue ;
		}
		bool flag = false;
		for (int i=0; i<frank.size(); i++){
			memset(dp, -1, sizeof dp);
			if(solve(0, i+1, i+1)){
				flag = true;
				break ;
			}
		}
		cout << (flag ? "YES\n" : "NO\n");
	}
}