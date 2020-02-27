#include <bits/stdc++.h>
using namespace std;

int calc(int x, int y, int side, vector < pair < int, int > >&vet){
	if(side == 1 && x+1 > 1000000000) return -1;
	if(side == 2 && y+1 > 1000000000) return -1;
	if(side == 3 && x-1 < 0) return -1;
	if(side == 4 && y-1 < 0) return -1;
	int ans = 0;
	for (int i=0; i<vet.size(); i++){
		if(side == 1 && vet[i].first > x) ans++;
		if(side == 2 && vet[i].second > y) ans++;
		if(side == 3 && vet[i].first < x) ans++;
		if(side == 4 && vet[i].second < y) ans++;
	}
	return ans;
}

int main(){
	int n, x, y;
	scanf("%d %d %d", &n, &x, &y);
	vector < pair < int, int > > vet;
	for (int i=0; i<n; i++){
		pair < int, int > x;
		scanf("%d %d", &x.first, &x.second);
		vet.push_back(x);
	}
	int mx = max(calc(x, y, 1, vet), max(calc(x, y, 2, vet), max(calc(x, y, 3, vet), calc(x, y, 4, vet))));
	if(calc(x, y, 1, vet) == mx){
		printf("%d\n%d %d", mx, x+1, y);
	}
	else if(calc(x, y, 2, vet) == mx){
		printf("%d\n%d %d", mx, x, y+1);
	}
	else if(calc(x, y, 3, vet) == mx){
		printf("%d\n%d %d", mx, x-1, y);
	}
	else {
		printf("%d\n%d %d", mx, x, y-1);
	}
}