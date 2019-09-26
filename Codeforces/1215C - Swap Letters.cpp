//https://codeforces.com/problemset/problem/1215/C

#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	string s1, s2;
	cin >> s1 >> s2;
	vector < int > ab, ba;
	for (int i=0; i<n; i++){
		if(s1[i] == s2[i]) continue ;
		if(s1[i] == 'a') ab.push_back(i);
		else ba.push_back(i);
	}
	if((((int)ab.size() + (int)ba.size()) & 1)) {
		puts("-1");
	}
	else {
		vector < pair < int, int > > ans;
		for (int i=0; i<(int)ab.size()-1; i+=2){
			ans.push_back({ab[i]+1, ab[i+1]+1});
		}
		for (int i=0; i<(int)ba.size()-1; i+=2){
			ans.push_back({ba[i]+1, ba[i+1]+1});
		}
		if((int)ab.size() & 1){
			ans.push_back({ab.back()+1, ab.back()+1});
			ans.push_back({ab.back()+1, ba.back()+1});
		}
		cout << (int)ans.size() << endl;
		for (pair < int, int > x : ans){
			cout << x.first << ' ' << x.second << endl;
		}
	}
	return 0;
}
