#include <bits/stdc++.h>
using namespace std;

map < pair < int, int >, long long > mapa;
pair <int, int> vet[2002];

int main(){
	int n;
	scanf("%d", &n);
	for (int i=0; i<n; i++){
		int x, y;
		scanf("%d %d", &x, &y);
		vet[i] = make_pair(x, y);
	}
	long long ans = 0;
	for (int i=0; i<n; i++){
		for (int j=i+1; j<n; j++){
			pair < int, int > v = make_pair(vet[i].first-vet[j].first, vet[i].second - vet[j].second);
			long long ant = mapa[make_pair(vet[i].first-vet[j].first, vet[i].second - vet[j].second)] + mapa[make_pair(-(vet[i].first-vet[j].first), -(vet[i].second - vet[j].second))];
			ans -= ((ant * (ant-1))/2);
			ant++;
			ans += ((ant * (ant-1))/2);
			mapa[make_pair(vet[i].first-vet[j].first, vet[i].second - vet[j].second)] = ant;
		}
	}
	printf("%lld\n", ans/2);
}