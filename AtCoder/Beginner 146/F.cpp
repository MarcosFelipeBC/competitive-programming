#include <bits/stdc++.h>
#define oo 0x3f3f3f3f
using namespace std;

const int N = 100005;
int path[N], dp[N];
pair < int, int >st[N << 2];

void update(int p, int l, int r, int pos, int val){
	if(pos > r || pos < l) return ;
	if(l == r){
		st[p] = {val, l};
		return ;
	}
	int mid = (l + r) >> 1;
	update(p << 1, l, mid, pos, val);
	update(p << 1|1, mid+1, r, pos, val);
	if(st[p << 1].first <= st[p << 1|1].first) st[p] = st[p << 1];
	else st[p] = st[p << 1|1];
}

pair < int, int > query(int p, int l, int r, int a, int b){
	if(a > r || b < l) return {oo, oo};
	if(l >= a && r <= b){
		return st[p];
	}
	int mid = (l + r) >> 1;
	pair < int, int > x = query(p << 1, l, mid, a, b), y = query(p << 1|1, mid+1, r, a, b);
	if(x.first <= y.first) return x;
	return y;
}

int main(){
	int n, m;
	cin >> n >> m;
	string str;
	cin >> str;
	memset(st, oo, sizeof st);
	dp[n] = (str[n] == '0') ? 0 : oo;
	path[n] = -1;
	update(1, 0, n, n, dp[n]);
	for (int i=n-1; i>=0; i--){
		pair < int, int > nxt = query(1, 0, n, i+1, i+m);
		if(str[i] == '1' || nxt.first == oo){
			dp[i] = path[i] = oo;
		}
		else {
			dp[i] = nxt.first+1;
			path[i] = nxt.second;
		}
		update(1, 0, n, i, dp[i]);	
	}
	if(dp[0] != oo){
		int now = 0;
		while (path[now] != -1){
			printf("%d", path[now] - now);
			if(path[path[now]] != -1) printf(" ");
			else printf("\n");
			now = path[now];
		}
	}
	else printf("-1\n");
}
