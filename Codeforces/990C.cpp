#include <bits/stdc++.h>
using namespace std;

map < int, vector < int > > mapa;

int main(){
	int n;
	cin >> n;
	vector < pair < int, int > > vet;
	for (int i=0; i<n; i++){
		string str; 
		cin >> str;
		int aux = 0, mn = 1000000000;
		for (int j=0; j<str.size(); j++){
			if(str[j] == '(') aux++;
			else aux--;
			mn = min(mn, aux);
		}
		vet.push_back({mn, aux});
	}
	sort(vet.begin(), vet.end(), greater < pair < int, int > >());
	for (int i=0; i<n; i++){
		mapa[vet[i].second].push_back(vet[i].first);
	}
	long long ans = 0LL;
	for (int i=0; i<n; i++){
		if(vet[i].first < 0) continue ;
		vector < int > &v = mapa[-vet[i].second];
		int lo = 0, hi = v.size()-1, resp = -1;
		while (lo <= hi)
		{
			int mid = (lo + hi) >> 1;
			if(vet[i].second >= -v[mid])
			{
				resp = mid;
				lo = mid+1;
			}
			else hi = mid-1;
		}

		ans += (resp+1);
	}
	cout << ans << endl;
}