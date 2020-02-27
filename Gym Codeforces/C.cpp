#include <bits/stdc++.h>
using namespace std;

const int N = 26;

vector < string > vet;

struct no
{
	int mn, letter, fim;
	no *nxt[N];
	no()
	{
		mn = letter = -1, fim = 0;
		for (int i=0; i<N; i++) nxt[i] = NULL;
	}
	int query(int pos, const int& id)
	{
		if(mn == -1) return -1;
		if(pos == vet[id].size()) return mn;
		int c = vet[id][pos] - 'a';
		if(nxt[c] == NULL) return -1;
		return nxt[c]->query(pos+1, id);
	}

	void insert(int pos, const int& id)
	{
		if(pos == vet[id].size())
		{
			fim = 1;
			mn = id;
			letter = -1;
			return ;
		}
		char c = vet[id][pos] - 'a';
		if(nxt[c] == NULL) nxt[c] = new no();
		nxt[c]->insert(pos+1, id);
		int auxmn = mn, auxletter = letter;
		for (int c=0; c<N; c++){
			if(nxt[c] != NULL)
			{
			 	if((auxmn == -1) || (nxt[c]->mn != -1 && vet[nxt[c]->mn].size() < vet[auxmn].size())){
					auxletter = c;
					auxmn = nxt[c]->mn;
				}
			}
		}
		mn = auxmn, letter = auxletter;
		// if(mn == -1){
		// 	mn = id;
		// 	letter = c;
		// }
		// else {
		// 	if(letter != -1){
		// 		if(letter > c) {
		// 			if(vet[mn].size() >= vet[id].size()){
		// 				mn = id;
		// 				letter = c;
		// 			}
		// 		}
		// 		else if(letter < c)
		// 		{
		// 			if(vet[mn].size() > vet[id].size()){
		// 				mn = id;
		// 				letter = c;
		// 			}
		// 		}
		// 		else {
		// 			mn = nxt[c]->mn;
		// 		}
		// 	}
		// }
	}

	void erase(int pos, const int& id)
	{
		if(pos != vet[id].size()) {
			int c = vet[id][pos] - 'a';
			if(nxt[c] == NULL) nxt[c] = new no();
			nxt[c]->erase(pos+1, id);
		}
		else fim = 0;
		if(fim == 1) {
			return ;
		}
		int auxmn = -1, auxletter = -1;
		for (int c=0; c<N; c++){
			if(nxt[c] != NULL)
			{
			 	if((auxmn == -1) || (nxt[c]->mn != -1 &&  vet[nxt[c]->mn].size() < vet[auxmn].size())){
					auxletter = c;
					auxmn = nxt[c]->mn;
				}
			}
		}
		mn = auxmn, letter = auxletter;
	}
};

int main()
{
	int q;
	cin >> q;
	int cnt=0;
	no *trie = new no();
	while (q--)
	{
		int op;
		cin >> op;
		if(op == 1)
		{
			string str;
			cin >> str;
			vet.push_back(str);
			trie->insert(0, cnt);
		}
		else if(op == 2)
		{
			int id;
			cin >> id;
			id--;
			vet.push_back("-");
			trie->erase(0, id);
		}
		else 
		{
			string str;
			cin >> str;
			vet.push_back(str);
			int ans = trie->query(0, cnt);
			if(ans != -1) ans++;
			cout << ans << endl;
		}
		cnt++;
	}
}