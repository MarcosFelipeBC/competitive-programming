#include <bits/stdc++.h>
using namespace std;

int qtd[10];

int test(int i){
	memset(qtd, 0, sizeof qtd);
	while (i){
		qtd[i%10]++;
		if(qtd[i%10] > 1) return 0;
		i /= 10;
	}
	return 1;
}

int main(){
	int a, b;
	cin >> a >> b;
	for (int i=a; i<=b; i++){
		if(test(i)){
			cout << i << endl;
			return 0;
		}
	}
	cout << -1 << endl;
}