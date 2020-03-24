//https://www.hackerearth.com/pt-br/practice/data-structures/advanced-data-structures/trie-keyword-tree/practice-problems/algorithm/micros-house-30/description/

#include <bits/stdc++.h>
using namespace std;

int tt = 1;
int trie[10001*31][2], mat[10005][20];

void insert(int val)
{
	int now = 0;
	for (int i=30; i>=0; i--){
		int b = (val >> i)&1;
		if(trie[now][b] == 0){
			trie[now][b] = tt++;
		}
		now = trie[now][b];
	}
}

int query(int val)
{
	int now = 0;
	int ans = 0;
	for (int i=30; i>=0; i--){
		int b = (val >> i)&1;
		if(trie[now][b^1] != 0){
			ans |= (1 << i);
			now = trie[now][b^1];
		}
		else now = trie[now][b];
	}
	return ans;
}

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i=0; i<n ;i++){
		for (int j=0; j<m; j++){
			scanf("%d", &mat[i][j]);
			if(j) mat[i][j] ^= mat[i][j-1];
		}
	}
	int ans = 0;
	for (int l=0; l<m; l++){
		for (int r=l; r < m; r++){
			memset(trie, 0, sizeof trie);
			tt = 1;
			insert(0);
			int acc = 0;
			for (int i=0; i<n; i++){
				int val = mat[i][r];
				if(l) val ^= mat[i][l-1];
				acc ^= val;
				ans = max(ans, query(acc));
				insert(acc);
			}
		}
	}
	printf("%d\n", ans);
}
