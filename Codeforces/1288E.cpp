#include <bits/stdc++.h>
using namespace std;

const int N = 300005;
int vet[N], bit[2][N], last[N];
pair < int, int > resp[N];

void update(int id, int pos, int val)
{
	for (; pos < N; pos += (pos & (-pos)))
	{
		bit[id][pos] += val;
	}
}

int query(int id, int pos)
{
	int ans = 0;
	for (; pos > 0; pos -= (pos & (-pos)))
	{
		ans += bit[id][pos];
	}
	return ans;
}

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);	
	for (int i=1; i<=n; i++) resp[i] = {i, i};
	for (int i=1; i<=m; i++){
		scanf("%d", &vet[i]);
		if(last[vet[i]] == 0)
		{
			int qtd = query(1, n) - query(1, vet[i]);
			resp[vet[i]].first = 1;
			resp[vet[i]].second += qtd;
			update(1, vet[i], 1);
			update(0, i, 1);
		}
		else
		{
			int qtd = query(0, i) - query(0, last[vet[i]]);
			resp[vet[i]].second = max(resp[vet[i]].second, qtd+1);
			update(0, last[vet[i]], -1);
			update(0, i, 1);
		}
		last[vet[i]] = i;
	}
	for (int i=1; i<=n; i++)
	{
		if(last[i] == 0)
		{
			int qtd = query(1, n) - query(1, i);
			resp[i].second += qtd;
		}
		else 
		{
			int qtd = query(0, m) - query(0, last[i]);
			resp[i].second = max(resp[i].second, qtd+1);

		}
		printf("%d %d\n", resp[i].first, resp[i].second);
	}
}