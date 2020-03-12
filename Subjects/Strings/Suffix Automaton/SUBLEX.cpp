//https://www.spoj.com/problems/SUBLEX/

#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

struct no 
{
	int link, sz;
	map < char, int > nxt;
};

no sa[N];
int tt, last, dp[N];

void add(char c)
{
	int cur = tt++;
	sa[cur].sz = sa[last].sz+1;
	int p = last;
	while (p != -1 && !sa[p].nxt.count(c))
	{
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
			sa[q].link = clone;
			sa[cur].link = clone;
			while (p != -1 && sa[p].nxt.count(c) && sa[p].nxt[c] == q){
				sa[p].nxt[c] = clone;
				p = sa[p].link;
			}
		}
	}
	last = cur;
}

void build(string &str)
{
	sa[0].link = -1;
	sa[0].sz = 0;
	tt = 1, last = 0;
	for (int i=0; i<str.size(); i++){
		add(str[i]);
	}
}


void solveDP(int u)
{
	dp[u] = 1;
	for (auto it = sa[u].nxt.begin(); it != sa[u].nxt.end(); it++)
	{
		int v = it->second;
		if(dp[v] == 0) solveDP(v);
		dp[u] += dp[v];
	}
}

string solveKth(int k)
{
	string ans;
	k++;
	int pos = 0;
	while (k != 1){
		k--;
		for (auto it = sa[pos].nxt.begin(); it != sa[pos].nxt.end(); it++)
		{
			int v = it->second;
			if(dp[v] < k) k -= dp[v];
			else {
				ans.push_back(it->first);
				pos = v;
				break;
			}
		}
	}
	return ans;
}

int main()
{
	string str;
	cin >> str;
	build(str);
	int q;
	cin >> q;
	while (q-- > 0)
	{
		int k;
		cin >> k;
		solveDP(0);
		cout << solveKth(k) << endl;
	}
}