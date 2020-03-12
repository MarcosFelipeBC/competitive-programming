#include <bits/stdc++.h>
using namespace std;

const int N = 300;

int mat[30][30];
int vist[N];

void dfs(int u, string &ans)
{
	vist[u] = 1;
	ans.push_back(char(u+'a'));
	for (int i=0; i<26; i++){
		if(mat[u][i] == 1 && vist[i] == 0){
			dfs(i, ans);
		}
	}
	return ;
}

int main()
{
	int t;
	cin >> t;
	while (t-- > 0)
	{
		memset(mat, 0, sizeof mat);
		memset(vist, 0, sizeof vist);
		string str;
		cin >> str;
		for (int i=0; i<str.size(); i++){
			if(i-1 >= 0) mat[str[i]-'a'][str[i-1]-'a'] = mat[str[i-1]-'a'][str[i]-'a']=  1;
			if(i+1 < str.size()) mat[str[i]-'a'][str[i+1]-'a'] = mat[str[i+1]-'a'][str[i]-'a']=  1;;
		}
		int aux = 0;
		bool flag = true;
		for (int i=0; i<26; i++){
			int cnt = 0;
			for (int j=0; j<26; j++){
				if(mat[i][j] == 1) cnt++;
			}
			if(cnt != 1 && cnt != 2 && cnt != 0){
				flag = false;
				break;
			}
			if(cnt == 1) aux++;
		}
		string ans;
		if(str.size() == 1)
		{
			ans = "abcdefghijklmnopqrstuvwxyz";
		}
		else if(aux != 2){
			flag = false;
		}
		
		else {
			for (int i=0; i<26; i++){
				int cnt = 0;
				for (int j=0; j<26; j++){
					if(mat[i][j] == 1) cnt++;
				}
				if(cnt == 1){
					dfs(i, ans);
					break;
				}
			}
		}
		for (int i='a'; i<='z'; i++){
			bool found = false;
			for (char c: ans){
				if(c == i) found = true;
			}
			if(!found) ans.push_back(char(i));
		}
		if(!flag) {
			puts("NO");
		}
		else {
			puts("YES");
			cout << ans << endl;
		}
	}
}