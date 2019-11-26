#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
int orig[N], ans[N], st[N << 2];
pair < int, int > vet[N];
vector < pair < int, int > > queries[N];

bool cmp(pair < int, int > a, pair < int, int > b){
	if(a.first != b.first) return a.first > b.first;
	return a.second < b.second;
}

void update(int p, int l, int r, int pos){
	if(l > pos || r < pos) return ;
	if(l == r) {
		st[p]++;
		return ;
	}
	int mid = (l + r) >> 1;
	update(p << 1, l, mid, pos);
	update(p << 1|1, mid+1, r, pos);
	st[p] = st[p << 1] + st[p << 1|1];
}

int query(int p, int l, int r, int goal){
	if(l == r) return l;
	int mid = (l + r) >> 1;
	if(st[p << 1] >= goal)
		return query(p << 1, l, mid, goal);
	return query(p << 1|1, mid+1, r, goal - st[p << 1]);
}

int main(){
	int n;
	scanf("%d", &n);
	for (int i=0; i<n; i++){
		scanf("%d", &orig[i]);
		vet[i] = {orig[i], i};
	}
	sort(vet, vet+n, cmp);
	int m;
	scanf("%d", &m);
	for (int i=0; i<m; i++){
		int k, pos;
		scanf("%d %d", &k, &pos);
		queries[k].push_back({pos, i});
	}
	for (int i=0; i<n; i++){
		update(1, 0, n-1, vet[i].second);
		//cout << vet[i].first << ' ' << vet[i].second << endl;
		for (pair < int, int > x : queries[i+1]){
			int pos = query(1, 0, n-1, x.first);
			ans[x.second] = orig[pos];
			//cout << "ans: " << i+1 << ' ' << pos << ' ' << orig[pos] << endl;
		}
	}
	for (int i=0; i<m; i++){
		printf("%d\n", ans[i]);
	}
}
