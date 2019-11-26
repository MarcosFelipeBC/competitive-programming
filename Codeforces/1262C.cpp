#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while (t-- > 0){
		int n, k;
		cin >> n >> k;
		string str;
		cin >> str;
		vector < pair < int, int > > ans;
		k--;
		for (int i=0; i<n; i++){
			if(k == 0){
				int pos = i;
				while (pos < n && str[pos] != '('){
					pos++;
				}
				if(pos == n) break;
				reverse(str.begin()+i, str.begin()+pos+1);
				ans.push_back({i+1, pos+1});
			}
			else {
				int pos1 = i, pos2 = i+1;
				while (pos1 < n && str[pos1] != '('){
					pos1++;
				}
				reverse(str.begin()+i, str.begin()+pos1+1);
				ans.push_back({i+1, pos1+1});
				while (pos2 < n && str[pos2] != ')'){
					pos2++;
				}
				reverse(str.begin()+i+1, str.begin()+pos2+1);
				ans.push_back({i+2, pos2+1});
				i++;
				k--;
			}
		}
		cout << ans.size() << endl;
		for (pair < int, int > x : ans){
			cout << x.first << ' ' << x.second << endl;
		}
	}
}
