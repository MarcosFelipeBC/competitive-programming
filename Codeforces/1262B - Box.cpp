#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
int vist[N], vet[N];

int main(){
	int t;
	scanf("%d", &t);
	int cont = 1;
	while (t-- > 0){
		int n;
		scanf("%d", &n);
		for (int i=0; i<n; i++){
			scanf("%d", &vet[i]);
		}
		int now = 1;
		vector < int > ans;
		for (int i=0; i<n; i++){
			if(vist[vet[i]] == cont){
				while (now <= vet[i] && vist[now] == cont){
					now++;
				}
				if(now <= vet[i]){
					vist[now] = cont;
					ans.push_back(now);
				}
			}
			else {
				ans.push_back(vet[i]);
				vist[vet[i]] = cont;
			}
		}
		cont++;
		if(ans.size() != n) {
			printf("-1\n");
			continue ;
		}
		for (int i=0; i<n; i++){
			printf("%d ", ans[i]);
		}
		printf("\n");
	}
}
