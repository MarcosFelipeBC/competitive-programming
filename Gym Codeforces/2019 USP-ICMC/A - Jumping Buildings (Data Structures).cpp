//https://codeforces.com/gym/102302/problem/A

#include <bits/stdc++.h>
#define oo 0x3f3f3f3f
using namespace std;

const int N = 100005;
int vet[N];

int st[N << 2];

void update(int p, int l, int r, int pos, int val){
	if(l > pos || r < pos) return ;
	if(l == r) {
		st[p] = val;
		return ;
	}
	int mid = (l + r) >> 1;
	update(p << 1, l, mid, pos, val);
	update(p << 1|1, mid+1, r, pos, val);
	st[p] = min(st[p << 1], st[p << 1|1]);
}

int query(int p, int l, int r, int a, int b){
	if(l >= a && r <= b) return st[p];
	int mid = (l + r) >> 1;
	if(a > mid) return query(p << 1|1, mid+1, r, a, b);
	else if(b <= mid) return query(p << 1, l, mid, a, b);
	return min(query(p << 1, l, mid, a, b), query(p << 1|1, mid+1, r, a, b));
}

int main(){
	int n;
	scanf("%d", &n);
	for (int i=0; i<n; i++){
		scanf("%d", &vet[i]);
	}
	memset(st, oo, sizeof st);
	vector < int > ans;
	for (int i=n-1; i>=0; i--){
		int pos = query(1, 0, 100000, vet[i]+1, 100000);
		if(pos > min(n-1, i+vet[i])) ans.push_back(min(n-1, i+vet[i]) - i);
		else ans.push_back(pos-1-i);
		update(1, 0, 100000, vet[i], i);
	}
	reverse(ans.begin(), ans.end());
	for (int i=0; i<n; i++){
		if(i) printf(" ");
		printf("%d", ans[i]);
	}
	puts("");
}
