//https://codeforces.com/contest/455/problem/B

#include <bits/stdc++.h>
using namespace std;

struct no {
	bool win, lose;
	no *nxt[30];

	no(){
		win = lose = false;
		for (int i=0; i<30; i++) nxt[i] = NULL;
	}
	
	void insert(const string& s, int pos)
	{
		if(pos == s.size()) {
			lose = true, win = false;
			return ;
		}
		int c = s[pos] - 'a';
		if(nxt[c] == NULL) nxt[c] = new no();
		nxt[c]->insert(s, pos+1);
	}

	void solve()
	{
		for (int i=0; i<30; i++){
			if(nxt[i] == NULL) continue ;
			nxt[i]->solve();
			if(!nxt[i]->win) win = true;
			if(!nxt[i]->lose) lose = true;
		}
	}
};

int main(){
	int n, k;
	cin >> n >> k;
	no *root = new no();
	for (int i=0; i<n; i++){
		string s;
		cin >> s;
		root->insert(s, 0);
	}
	root->solve();
	bool win = false, lose = false;
	for (int i=0; i<30; i++){
		if(root->nxt[i] == NULL) continue ;
		if(!root->nxt[i]->win) win = true;
		if(!root->nxt[i]->lose) lose = true;
	}
	if(!win) puts("Second");
	else if(lose) puts("First");
	else puts((k & 1) ? "First" : "Second");
}