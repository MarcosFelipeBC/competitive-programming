#include <bits/stdc++.h>
using namespace std;

const int N = 50005;
int vet[N];

struct node {
	int left, right, best, sum;
	node(){
		left = right = best = sum = 0;
	}
	node(int a, int b, int c, int d){
		left = a, right = b, best = c, sum = d;
	}
}st[N << 2];

node join(node a, node b){
	node ans;
	ans.sum = a.sum + b.sum;
	ans.left = max(a.left, a.sum + b.left);
	ans.right = max(b.right, a.right + b.sum);
	ans.best = max(a.right + b.left, max(a.best, b.best));
	return ans;
}

void build(int p, int l, int r){
	if(l == r){
		st[p] = node(vet[l], vet[l], vet[l], vet[l]);
		return ;
	}
	int mid = (l + r) >> 1;
	build(p << 1, l, mid);
	build(p << 1|1, mid+1, r);
	st[p] = join(st[p << 1], st[p << 1|1]);
}

node query(int p, int l, int r, int a, int b){
	if(l >= a && r <= b) return st[p];
	int mid = (l + r) >> 1;
	if(a > mid) return query(p << 1|1, mid+1, r, a, b);
	if(b <= mid) return query(p << 1, l, mid, a, b);
	return join(query(p << 1, l, mid, a, b), query(p << 1|1, mid+1, r, a, b));
}

int main(){
	int n;
	scanf("%d", &n);
	for (int i=0; i<n; i++) scanf("%d", &vet[i]);
	int q;
	scanf("%d", &q);
	build(1, 0, n-1);
	while (q-- > 0){
		int l, r;
		scanf("%d %d", &l, &r);
		l--, r--;
		printf("%d\n", query(1, 0, n-1, l, r).best);
	}
}
