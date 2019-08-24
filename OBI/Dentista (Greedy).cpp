//http://www.codcad.com/problem/48

#include <bits/stdc++.h>
using namespace std;

const int NMAX = 10004;

struct intervalo {
	int l, r;
		
	bool operator < (intervalo aux) const {
		if(r < aux.r) return true;
		else if(aux.r < r) return false;
		else {
			if(l < aux.l) return true;
			else return false;
		}
	}
	
}vet[NMAX];

int main(){
	int n;
	scanf("%d", &n);
	for (int i=0; i<n; i++) scanf("%d %d", &vet[i].l, &vet[i].r);
	sort(vet, vet+n);
	int tempo = 0, resp = 0;
	for (int i=0; i<n; i++){
		if(vet[i].l >= tempo){
			resp++;
			tempo = vet[i].r;
		}
	}
	printf("%d\n", resp);
}






