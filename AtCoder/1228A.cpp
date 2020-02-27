#include <bits/stdc++.h>
using namespace std;

int qtd[300];

int test(int i){
	for (int i=0; i<10; i++) qtd[i+48] = 0;
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
}