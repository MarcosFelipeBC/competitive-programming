#include <bits/stdc++.h>
using namespace std;

const int N = 1000006;

int mapa[N];
unordered_map < int , vector < pair < int, int > > > where;
int n, m, p[N], sz[N], mx;

int getId(int x, int y)
{
	return (x-1)*m + y ;
}

int find(int u){
	return p[u] = (p[u] == u) ? u : find(p[u]);
}

void join(int u, int v)
{
	u = find(u), v = find(v);
	p[v] = u;
	sz[u] += sz[v];
	sz[v] = 0;
	mx = max(mx, sz[u]);
}

int main(){
	int s;
	scanf("%d %d %d", &s, &n, &m);
	vector < int > vet;
	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			int x;
			scanf("%d", &x);
			mapa[getId(i+1, j+1)] = x;
			vet.push_back(x);
			where[x].push_back({i+1, j+1});
		}
	}
	for (int i=1; i<=n*m; i++){
		p[i] = i;
		sz[i] = 1;
	}
	mx = 1;
	sort(vet.rbegin(), vet.rend());
	int dept = -1;
	for (int i=0; i<vet.size(); i++)
	{
		if(i && vet[i] == vet[i-1]) continue ;
		int tam = where[vet[i]].size();
		for (int j = 0; j<tam; j++){
			int x = where[vet[i]][j].first, y = where[vet[i]][j].second;
			if(y+1 <= m){
				if(mapa[getId(x, y+1)] >= vet[i]){
					if(find(getId(x, y)) != find(getId(x, y+1)))
					{
						join(getId(x, y), getId(x, y+1));
					}
				}
			}
			if(y-1 > 0){
				if(mapa[getId(x, y-1)] >= vet[i]){
					if(find(getId(x, y)) != find(getId(x, y-1)))
					{
						join(getId(x, y), getId(x, y-1));
					}
				}
			}

			if(x+1 <= n){
				if(mapa[getId(x+1, y)] >= vet[i]){
					if(find(getId(x, y)) != find(getId(x+1, y)))
					{
						join(getId(x, y), getId(x+1, y));
					}
				}
			}
			if(x-1 > 0){
				if(mapa[getId(x-1, y)] >= vet[i]){
					if(find(getId(x, y)) != find(getId(x-1, y)))
					{
						join(getId(x, y), getId(x-1, y));
					}
				}
			}
		}
		if(mx >= s) {
			dept = vet[i];
			break;
		}
	}
	printf("%d\n", dept);
}