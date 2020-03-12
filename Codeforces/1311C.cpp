#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
int aux[N][30], ans[30];

int main(){
	int t;
	cin >> t;
	while (t-- > 0)
	{
		int n, m;
		cin >> n >> m;
		string s;
		cin >> s;
		for (int i=0; i<n; i++)
			for (int j=0; j<26; j++) aux[i][j] = 0;
		for (int i=0; i<n; i++){
			for (int j=0; j<26; j++){
				if(i) aux[i][j] = aux[i-1][j];
			}
			aux[i][s[i]-'a']++;
		}
		for (int i=0; i<30; i++) ans[i] = 0;
		for (int i=0; i<m; i++){
			int pos;
			cin >> pos;
			pos--;
			for (int j=0; j<26; j++){
				ans[j] += aux[pos][j];
			}
		}
		for (int i=0; i<n; i++){
			ans[s[i]-'a']++;
		}
		for (int i=0; i<26; i++){
			cout << ans[i] << ' ';
		}
		cout << endl;
	}
}