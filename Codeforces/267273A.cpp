#include <bits/stdc++.h>
using namespace std;

int qtd[300];

int main()
{
	string str;
	cin >> str;
	int n = str.size();
	if(n&1){
		puts("NO");
		return 0;
	}
	else {
		string aux = str;
		sort(aux.begin(), aux.end());
		for (int i=n/2; i<n; i++) str[i-n/2] = aux[i];
		for (int i=0; i<n/2; i++) str[i+n/2] = aux[i];
		for (int i=0; i<n/2; i++){
			if(str[i] == str[n-1-i]) {
				puts("NO");
				return 0;
			}
		}
		puts("YES");
		return 0;
	}
}