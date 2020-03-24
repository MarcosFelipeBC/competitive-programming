//https://www.hackerearth.com/pt-br/practice/data-structures/advanced-data-structures/trie-keyword-tree/tutorial/

#include <bits/stdc++.h>
using namespace std;

struct no
{
	no *nxt[30];
	int mx;
	
	no() {
		for (int i=0; i<30; i++) nxt[i] = NULL;
		mx = -1;
	}

	void insert(const string& s, int pos, int priority)
	{
		mx = max(mx, priority);
		if(pos == s.size()) return ;
		int c = (s[pos] - 'a');
		if(nxt[c] == NULL) nxt[c] = new no();
		nxt[c]->insert(s, pos+1, priority);
	}

	int query(const string& s, int pos)
	{
		if(pos == s.size()) return mx;
		int c = (s[pos] - 'a');
		if(nxt[c] == NULL) nxt[c] = new no();
		return nxt[c]->query(s, pos+1);
	}
};

int main()
{
	no *root = new no();
	int n, q;
	cin >> n >> q;
	for (int i=0; i<n; i++){
		string s;
		int priority;
		cin >> s >> priority;
		root->insert(s, 0, priority);
	}
	while (q-- > 0)
	{
		string s;
		cin >> s;
		cout << root->query(s, 0) << endl;
	}
}