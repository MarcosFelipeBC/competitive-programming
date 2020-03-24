#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
queue < int > vet[N];
set < int > prince;

int main()
{
	int t;
	scanf("%d", &t);
	while (t-- > 0)
	{
		int n;
		scanf("%d", &n);
		for (int i=1; i<=n; i++) prince.insert(i);
		for (int i=0; i<n; i++){
			int k;
			scanf("%d", &k);
			for (int j=0; j<k; j++){
				int x;
				scanf("%d", &x);
				vet[i].push(x);
			}
		}
		int add = -1;
		for (int i=0; i<n; i++){
			while (!vet[i].empty() && prince.find(vet[i].front()) == prince.end()){
				vet[i].pop();
			}
			if(vet[i].empty()) {
				add = i;
			}
			else {
				prince.erase(vet[i].front());
			}
		}
		if(add != -1) {
			puts("IMPROVE");
			printf("%d %d\n", add+1, *(prince.begin()));
		}
		else {
			puts("OPTIMAL");
		}
		prince.clear();
		for (int i=0; i<n; i++){
			while (!vet[i].empty()) vet[i].pop();
		}
	}
}