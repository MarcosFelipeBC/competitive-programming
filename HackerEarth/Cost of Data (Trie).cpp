//https://www.hackerearth.com/pt-br/practice/data-structures/advanced-data-structures/trie-keyword-tree/practice-problems/algorithm/cost-of-data-11/

#include <bits/stdc++.h>
using namespace std;

int qtd = 0;

struct no
{
	no *nxt[30];
	no(){
		for (int i=0; i<30; i++) nxt[i] = NULL;
	}
	
	void insert(const string& s, int pos)
	{
		if(pos == s.size()) return ;
		int c = (s[pos]-'a');
		if(nxt[c] == NULL){
			qtd++;
			nxt[c] = new no();
		}
		nxt[c]->insert(s, pos+1);
	}
};

int main()
{
	no *root = new no();
	qtd++;
	int n;
	cin >> n;
	for (int i=0; i<n; i++){
		string s;
		cin >> s;
		root->insert(s, 0);
	}
	cout << qtd << endl;
}