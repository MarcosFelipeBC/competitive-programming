#include <bits/stdc++.h>
using namespace std;

set < int > s;
const int N = 300003;
int vet[N], aux[N];

int main(){
	int n;
	scanf("%d", &n);
	for (int i=1; i<=n; i++){
		s.insert(i);
	}
	for (int i=0; i<n; i++){
		scanf("%d", &vet[i]);
		if(vet[i] != 0) s.erase(vet[i]);
		aux[i] = vet[i];
	}
	int last = -1;
	bool flag = true;
	for (int i=n-1; i>=0; i--){
		if(vet[i] == 0){
			if(i+1 != *(s.begin())){
				aux[i] = *(s.begin());
				s.erase(aux[i]);
				last = i;
			}
			else {
				if(last == -1){
					flag = false;
					break;
				}
				aux[i] = aux[last];
				aux[last] = *(s.begin());
				s.erase(aux[last]);
				last = i;
			}
		}
		else aux[i] = vet[i];
	}
	if(!flag){
		for (int i=0; i<n; i++){
			if(vet[i] == 0){
				if(i+1 != *(s.begin())){
					aux[i] = *(s.begin());
					s.erase(aux[i]);
					last = i;
				}
				else {
					if(last == -1){
						flag = false;
						break;
					}
					aux[i] = aux[last];
					aux[last] = *(s.begin());
					s.erase(aux[last]);
					last = i;
				}
			}
			else aux[i] = vet[i];
		}
	}
	for (int i=0; i<n; i++){
		printf("%d ", aux[i]);
	}
	printf("\n");
}