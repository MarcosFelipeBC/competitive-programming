//https://codeforces.com/contest/1203/problem/D2

#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
int appear[2][N];

int main(){
	string s, t;
	cin >> s >> t;
	int j = 0;
	for (int i=0; i<s.size(); i++){
		if(s[i] == t[j]){
			appear[0][j] = i;
			j++;
			if(j == t.size()) break;
		}
	}
	j = (int)t.size()-1;
	for (int i=(int)s.size()-1; i>=0; i--){
		if(s[i] == t[j]){
			appear[1][j] = i;
			j--;
			if(j == -1) break;
		}
	}
	int ans = max(appear[1][0], (int)s.size() - appear[0][(int)t.size()-1]-1);
	for (int i=0; i<(int)t.size()-1; i++){
		ans = max(ans, appear[1][i+1] - appear[0][i] - 1);
	}
	cout << ans << endl;
}
