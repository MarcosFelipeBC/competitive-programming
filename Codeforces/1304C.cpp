#include <bits/stdc++.h>
using namespace std;

const int N = 105;
pair < int, pair < int, int > > vet[N];
int n;

bool solve(int temp)
{
	int l = temp, r = temp, time = 0;
	for (int i=0; i<n; i++){
		int moves = vet[i].first - time;
		r += moves;
		l -= moves;
		if(r < vet[i].second.first || l > vet[i].second.second) return false;
		l = max(l, vet[i].second.first);
		r = min(r, vet[i].second.second);
		time = vet[i].first;
	}
	return true;
}


int main()
{
	int t;
	scanf("%d", &t);
	while (t-- > 0)
	{
		int  m;
		scanf("%d %d", &n, &m);
		for (int i=0; i<n; i++){
			scanf("%d %d %d", &vet[i].first, &vet[i].second.first, &vet[i].second.second);
		}
		printf("%s\n", solve(m) ? "YES" : "NO");
	}
}