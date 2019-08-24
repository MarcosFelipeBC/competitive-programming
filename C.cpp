//https://codeforces.com/gym/102302/problem/C

#include <bits/stdc++.h>
using namespace std;

typedef pair < int, int > ii;
vector < ii > vet;
map < int, vector < int > > X;

int main(){
	int n;
	scanf("%d", &n);
	for (int i=0; i<n; i++){
		int x, y;
		scanf("%d %d", &x, &y);
		X[x].push_back(y);
		vet.push_back({x, y});
	}
	for (auto var : X) sort(X[var.first].begin(), X[var.first].end());
	int ans = 0;
	for (auto it = X.begin(); it != X.end(); it++){
		int x = it->first;
		int p = 0;
		while (p+1 < X[x].size()){
			int y = X[x][p], y2 = X[x][p+1];
			int minX1 = 1000000010, minX2 = 1000000010;	
			int in = 1000000010;
			for (int i=0; i<n; i++){X
				if(vet[i].second == y && vet[i].first > x) minX1 = min(minX1, vet[i].first);
				if(vet[i].second == y2 && vet[i].first > x) minX2 = min(minX2, vet[i].first);
				if(vet[i].second > y && vet[i].second < y2 && vet[i].first > x) in = min(in, vet[i].first);
			}
			if(minX1 != 1000000010 && minX1 == minX2 && in > minX1) ans++;
			p++;
		}
	}
	printf("%d\n", ans);
}
