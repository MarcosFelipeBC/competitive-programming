//https://codeforces.com/gym/101810/problem/C

#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	scanf("%d", &t);
	while (t-- > 0){
		int x;
		scanf("%d", &x);
		int cont=0;
		for (int i=0; i<31; i++){
			if((x & (1 << i)) != ((x-1)&(1 << i))) cont++; 
		}
		printf("%d\n", cont);
	}
}
