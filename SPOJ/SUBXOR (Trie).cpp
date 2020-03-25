#include <bits/stdc++.h>
using namespace std;

struct no {
	no* nxt[2];
	int amount;

	no(){
		nxt[0] = nxt[1] = NULL;
		amount = 0;
	}

	void insert(int val, int pos)
	{
		amount++;
		if(pos == -1) return ;
		int b = (val >> pos) & 1;
		if(nxt[b] == NULL) nxt[b] = new no();
		nxt[b]->insert(val, pos-1);
	}

	int query(int val, int k, int pos)
	{
		if(pos == -1) return 0;
		int bval = (val >> pos) & 1;
		int bk = (k >> pos) & 1;
		int ans = 0;
		if(bk){
			if(nxt[bval] != NULL) ans += nxt[bval]->amount;
			if(nxt[bval ^ 1] != NULL) ans += nxt[bval ^ 1]->query(val, k, pos-1);
		}
		else {
			if(nxt[bval] != NULL) ans += nxt[bval]->query(val, k, pos-1);
		}
		return ans;
	}

	void destroy()
	{
		if(nxt[0] != NULL){
			nxt[0]->destroy();
			free(nxt[0]);
			nxt[0] = NULL;
		}
		if(nxt[1] != NULL){
			nxt[1]->destroy();
			free(nxt[1]);
			nxt[1] = NULL;
		}
	}
};

int main()
{
	int t;
	cin >> t;
	while (t-- > 0)
	{
		int n, k;
		cin >> n >> k;
		no* root = new no();
		long long ans = 0LL, acc = 0;
		root->insert(0, 30);
		for (int i=0; i<n; i++){
			int x;
			cin >> x;
			acc ^= x;
			x = (long long)root->query(acc, k, 30);
			ans += x;
			root->insert(acc, 30);
		}
		cout << ans << endl;
		root->destroy();
		free(root);
		root = NULL;
	}
}
