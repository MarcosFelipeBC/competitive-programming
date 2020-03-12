#include <bits/stdc++.h>
using namespace std;

int ans[50000];

int main(){
	int n, m, M;
	cin >> n >> m;
	vector < int > window;
	for (int i = 1; i <= min(m, 2*n); i++){
		window.push_back(i);
	}
	vector <int> nonwindow;
	for (int i = n*2+1; i<=m; i++){
		nonwindow.push_back(i);
	}
	int cnt = 0;
	vector < int > ans;
	int idx1 = 0, idx2 = 0 ;
	while (cnt < m){
		if(idx2 < nonwindow.size()) ans.push_back(nonwindow[idx2++]), cnt++;
		if(idx1 < window.size()) ans.push_back(window[idx1++]), cnt++;
		if(idx2 < nonwindow.size()) ans.push_back(nonwindow[idx2++]), cnt++;
		if(idx1 < window.size()) ans.push_back(window[idx1++]), cnt++;
	}
	for (int i=0; i<m; i++) cout << ans[i] << ' ';
	cout << endl;
}