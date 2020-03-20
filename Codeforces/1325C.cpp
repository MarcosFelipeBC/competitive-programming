#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
vector < pair < int, int > > g[N];
int ans[N];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i=0; i<n-1; i++){
		int u, v;
		scanf("%d %d", &u, &v);
		g[u].push_back({v, i});
		g[v].push_back({u, i});
	}
	int mx = 0;
	for (int i=1; i<=n; i++){
		if(g[mx].size() < g[i].size()){
			mx = i;
		}
	}
	int now = 0;
	memset(ans, -1, sizeof ans);
	for (pair < int, int > v : g[mx])
	{
		ans[v.second] = now++;
	}
	for (int i=0; i<n-1; i++){
		if(ans[i] == -1) ans[i] = now++;
	}
	for (int i=0; i<n-1; i++) {
		cout << ans[i] << endl;
	}
}