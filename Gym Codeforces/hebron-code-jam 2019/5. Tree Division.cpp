//https://codeforces.com/gym/102157/problem/5

#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
int blockSum;
vector < int > g[N];

int dfs(int u, int p){
	int sz = 1;
	for (int v : g[u]){
		if(v == p) continue ;
		int sum = dfs(v, u);
		if(sum != blockSum) sz += sum;
	}
	return sz;
}

int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i=0; i<n-1; i++){
		int u, v;
		scanf("%d %d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	if(n%k != 0) puts("No");
	else {
		blockSum = n/k;
		int u = -1;
		for (int i=1; i<=n; i++) if(g[i].size() == 1) u = i;
		puts((dfs(u, u) == blockSum) ? "Yes" : "No");
	}
}
