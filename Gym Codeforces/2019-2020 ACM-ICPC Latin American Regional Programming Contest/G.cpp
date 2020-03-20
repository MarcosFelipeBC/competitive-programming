#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int tt, last;

struct no {
	int link, sz;
	map < char, int > nxt;
}sa[2*N];

void add(const char &c)
{
	int cur = tt++;
	sa[cur].sz = sa[last].sz+1;
	int p = last;
	while (p != -1 && !sa[p].nxt.count(c)){
		sa[p].nxt[c] = cur;
		p = sa[p].link;
	}
	if(p == -1) sa[cur].link = 0;
	else {
		int q = sa[p].nxt[c];
		if(sa[q].sz == sa[p].sz+1) sa[cur].link = q;
		else {
			int clone = tt++;
			sa[clone].sz = sa[p].sz+1;
			sa[clone].nxt = sa[q].nxt;
			sa[clone].link = sa[q].link;
			while (p != -1 && sa[p].nxt.count(c) && sa[p].nxt[c] == q){
				sa[p].nxt[c] = clone;
				p = sa[p].link;
			}
			sa[q].link = clone;
			sa[cur].link = clone;
		}
	}
	last = cur;
}

void build(const string &s)
{
	sa[0].link = -1;
	sa[0].sz = 0;
	tt = 1, last = 0;
	for (int i=0; i<s.size(); i++){
		add(s[i]);
	}
}

int main()
{
	string s;
	cin >> s;
	build(s);
	int q;
	cin >> q;
	while (q-- > 0){
		string query;
		cin >> query;
		int ans = 0;
		for (int i=0; i<query.size();){
			int p = 0;
			if(!sa[p].nxt.count(query[i])){
				ans = -1;
				break;
			}
			while (i < query.size() && sa[p].nxt.count(query[i])){
				p = sa[p].nxt[query[i]];
				i++;
			}
			ans++;			
		}
		cout << ans << endl;
	}
}