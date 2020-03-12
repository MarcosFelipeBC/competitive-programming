#include <bits/stdc++.h>
using namespace std;

int marked[105];

int main(){
	int n, m;
	cin >> n >> m;
	vector < string > vet;
	for (int i=0; i<n; i++){
		string str;
		cin >> str;
		vet.push_back(str);
	}
	string ans = "";
	for (int i=0; i<n; i++){
		if(marked[i]) continue ;
		for (int j=0; j<n; j++){
			if(i == j || marked[j]) continue ;
			string aux = vet[j];
			reverse(aux.begin(), aux.end());
 			if(vet[i] == aux){
				ans += vet[i];
				marked[i] = marked[j] = 1;
				break;
		
			}
		}
	}
	string aux = ans;
	reverse(aux.begin(), aux.end());
	for (int i=0; i<n; i++)
	{
		if(marked[i]) continue ;
		string aux = vet[i];
		reverse(aux.begin(), aux.end());
		if(aux == vet[i]) {
			ans += vet[i];
			break;
		}
	}
	ans += aux;
	cout << ans.size() << endl;
	cout << ans << endl;
}