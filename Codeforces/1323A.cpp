#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	scanf("%d", &t);
	while (t-- > 0)
	{
		int n;
		scanf("%d", &n);
		vector < int > odd;
		vector < int > even;
		for (int i=0; i<n; i++){
			int x;
			scanf("%d", &x);
			if((x & 1) && odd.size() < 2) odd.push_back(i+1);
			else if(!(x & 1) && even.size() == 0) even.push_back(i+1); 
		}
		if(even.size()){
			cout << 1 << endl;
			cout << even[0] << endl;
		}
		else if(odd.size() == 2) {
			cout << 2 << endl;
			cout << odd[0] << ' ' << odd[1] << endl;
		}
		else cout << -1 << endl;
	}
}