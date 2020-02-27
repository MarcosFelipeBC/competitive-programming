#include <bits/stdc++.h>
using namespace std;

const int N = 300005;
vector < int > vet[N];
int n, m;
vector < int > bin;
int mapa[1 << 9];

void down(int pos, int mask, int val){
	mapa[mask] = val;
	if(pos == m) return ;
	if(mask & (1 << pos)) down(pos+1, mask ^ (1 << pos), val);
	down(pos+1, mask, val);
}

pair < int, int > solve(int val){
	memset(mapa, -1, sizeof mapa);
	for (int i=0; i<n; i++){
		int mask = 0;
		for (int j=0; j<m; j++){
			if(vet[i][j] >= val) mask += (1 << j);
		}
		mapa[mask] = i;
	}
	for (int i=0; i<(1 << m); i++){
		if(mapa[i] != -1) down(0, i, mapa[i]);
	}

	for (int i=0; i<(1 << m); i++){
		if(mapa[i] != -1 && mapa[((1 << m)-1) ^ i] != -1) return {mapa[i]+1, mapa[((1 << m)-1) ^ i]+1};
	}

	return {-1, -1};
}

int main(){
	scanf("%d %d", &n, &m);
	for (int i=0; i<n; i++){
		vet[i].resize(m);
		for (int j=0; j<m; j++){
			scanf("%d", &vet[i][j]);
			bin.push_back(vet[i][j]);
		}
	}
	sort(bin.begin(), bin.end());
	int lo = 0, hi = bin.size()-1, resp = -1;
	while (lo <= hi){
		int mid = (lo + hi) >> 1;
		pair < int, int > x = solve(bin[mid]);
		if(x.first != -1){
			resp = mid;
			lo = mid+1;
		}
		else hi = mid-1;
	}
	pair < int, int > ans = solve(bin[resp]);
	assert(ans.first != -1 && ans.second != -1);
	printf("%d %d\n", ans.first, ans.second);
}