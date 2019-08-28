//https://www.urionlinejudge.com.br/judge/pt/problems/view/2700

#include <bits/stdc++.h>
#define oo 0x3f3f3f3f3f3f3f3f
using namespace std;

typedef long long ll;
const int N = 100005;

ll st[N << 2], dp[N];

void update(int p, int l, int r, int pos, ll val){
	if(l > pos || r < pos) return ;
	if(l == r) {
		st[p] = max(st[p], val);
		return ;
	}
	int mid = (l + r) >> 1;
	update(p << 1, l, mid, pos, val);
	update(p << 1|1, mid+1, r, pos, val);
	st[p] = max(st[p << 1], st[p << 1|1]);
}

ll query(int p, int l, int r, int a, int b){
	if(l >= a && r <= b) return st[p];
	int mid = (l + r) >> 1;
	if(a > mid) return query(p << 1|1, mid+1, r, a, b);
	if(b <= mid) return query(p << 1, l, mid, a, b);
	return max(query(p << 1, l, mid, a, b), query(p << 1|1, mid+1, r, a, b));
}

int main(){
	memset(st, -oo, sizeof st);
	int n;
	scanf("%d", &n);
	vector < pair < int, pair < int, ll > > > vet;
	vector < int > aux;
	for (int i=0; i<n; i++){
		int a, b;
		ll c;
		scanf("%d %d %lld", &a, &b, &c);
		vet.push_back({a, {b, c}});
		aux.push_back(b);
	}
	sort(vet.begin(), vet.end());
	sort(aux.begin(), aux.end());
	unordered_map < int, int > compress;
	int cnt=1;
	for (int i=0; i<n; i++){
		if(compress.count(aux[i]) == 0) {
			compress[aux[i]] = cnt++;
		}
	}
	ll soma = 0LL;
	for (int i=0; i<n; i++) {
		vet[i].second.first = compress[vet[i].second.first];
		if(i+1 < n && vet[i].first == vet[i+1].first && vet[i].second.first == compress[vet[i+1].second.first]) soma += vet[i].second.second;
		else {
			vet[i].second.second += soma;
			soma = 0LL;
		}
	}
	stack < int > p;
	dp[0] = vet[0].second.second;
	p.push(0);
	if(1 >= n || vet[1].first != vet[0].first) {
		p.pop();
		update(1, 0, cnt-1, vet[0].second.first, dp[0]);
	}
	ll ans = dp[0];
	for (int i=1; i<n; i++){
		ll val = query(1, 0, cnt-1, 0, vet[i].second.first-1);
		dp[i] = max(vet[i].second.second, val + vet[i].second.second);
		p.push(i);
		if(i+1 >= n || vet[i+1].first != vet[i].first){
			while (!p.empty()){
				update(1, 0, cnt-1, vet[p.top()].second.first, dp[p.top()]);
				p.pop();
			}
		}
		ans = max(ans, dp[i]);
	}
	printf("%lld\n", ans);
}
