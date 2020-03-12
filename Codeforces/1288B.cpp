#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	scanf("%d", &t);
	while (t-- > 0){
		int a, b;
		scanf("%d %d", &a, &b);
		int cnt = 0;
		int val = 9;
		for (int i=1; i<10; i++){
			if(b >= val) cnt++;
			else break;
			if(i+1 != 10) val *= 10;
			val += 9;
		} 
		printf("%lld\n", cnt * (long long)a);
	}	
}