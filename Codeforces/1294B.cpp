#include <bits/stdc++.h>
using namespace std;

using namespace std;

int main(){
	int t;
	cin >> t;
	while (t-- > 0)
	{
		int n;
		cin >> n;
		vector < pair < int, int > > vet(n);
		for (pair < int, int > &x : vet){
			cin >> x.first >> x.second;
		}
		sort(vet.begin(), vet.end());
		int x = 0, y = 0;
		string ans = "";
		bool resp = true;
		for (int i=0; i<n; i++){
			if(x > vet[i].first) {
				resp = false;
				break;
			}
			if(y > vet[i].second) {
				resp = false;
				break;
			}
			while (x < vet[i].first) {
				x++;
				ans.push_back('R');
			}
			while (y < vet[i].second) {
				y++;
				ans.push_back('U');
			}
		}
		if(resp) {
			cout << "YES\n" << ans << endl;
		}
		else cout << "NO" << endl;
	}
}