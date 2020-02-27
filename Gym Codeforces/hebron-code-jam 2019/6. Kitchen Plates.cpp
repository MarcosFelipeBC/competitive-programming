//https://codeforces.com/gym/102157/problem/6

#include <bits/stdc++.h>
using namespace std;

int main(){
	vector < pair < char, char > > vet;
	for (int i=0; i<5; i++){
		string str;
		cin >> str;
		if(str[1] == '>') swap(str[0], str[2]);
		vet.push_back({str[0], str[2]});
	}
	string str = "ABCDE";
	string ans = "impossible";
	do {
		bool flag = true;
		for (int i=0; i<5; i++){
			char a = vet[i].first, b = vet[i].second;
			if(str.find(a) > str.find(b)){
				flag = false;
				break;
			}
		}
		if(flag){
			ans = str;
			break;
		}
	}while (next_permutation(str.begin(), str.end()));
	cout << ans << endl;
}
