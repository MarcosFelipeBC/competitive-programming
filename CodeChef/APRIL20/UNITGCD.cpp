#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t-- > 0){
		int n;
		cin >> n;
		if(n == 1){
			cout << 1 << "\n" << 1 << ' ' << 1 << "\n";
		}
		else {
			int days = n/2;
			cout << days << "\n";
			int nxt;
			if(n & 1){
				nxt = 4;
				cout << 3 << ' ' << 1 << ' ' << 2 << ' ' << 3 << "\n";
			}
			else {
				nxt = 5;
				cout << 2 << ' ' << 1 << ' ' << 2  << "\n" << 2 << ' ' << 3 << ' ' << 4 << "\n";
			}
			for (; nxt <= n; nxt+=2){
				cout << 2 << ' ' << nxt << ' ' << nxt+1 << "\n"; 
			}
		}
	}
}