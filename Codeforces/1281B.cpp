#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t-- > 0){
		string a, b;
		cin >> a >> b;
		bool ans = false;
		for (int i=0; i<a.size(); i++){
			int mn = i;
			for (int j=i; j<a.size(); j++){
				if(a[j] <= a[mn])
				{
					mn = j;
				}
			}
			swap(a[i], a[mn]);
			if(a < b){
				ans = true;
				break;
			}
			swap(a[i], a[mn]);
		}
		cout << (ans ? a : "---") << endl;
	} 
}