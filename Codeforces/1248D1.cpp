#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	string str;
	cin >> str;
	int ans = 0, ansi, ansj;
	for (int j=0; j<n; j++){
		for (int k=j; k<n; k++){
			swap(str[j], str[k]);
			int menor = 1e9;
			int sum = 0;
			for (int i=0; i<n; i++){
				if(str[i] == '(') sum++;
				else sum--;
				menor = min(menor, sum);
			}
			if(sum != 0){
				printf("0\n1 1\n");
				return 0;
			}
			sum = 0;
			int resp = 0;
			for (int i=n-1; i>=0; i--){
				if(str[i] == '(') sum++;
				else sum--;
				if(menor + sum >= 0) resp++;
			}
			if(ans < resp){
				ans = resp;
				ansi = j+1, ansj = k+1;
			}
			swap(str[j], str[k]);
		}
	}
	printf("%d\n%d %d\n", ans, ansi, ansj);
}