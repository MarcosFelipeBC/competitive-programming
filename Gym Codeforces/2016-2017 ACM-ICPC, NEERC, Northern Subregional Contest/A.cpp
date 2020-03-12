#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("anniversary.in", "r", stdin);
	freopen("anniversary.out", "w", stdout);
	int n, m, x1, y1, x2, y2;
	cin >> n >> m >> x1 >> y1 >> x2 >> y2;
	if(y2 > y1){
		swap(x1, x2);
		swap(y1, y2);
	}
	if(x1 == x2){
		cout << 0 << ' ' << y1 << ' ' << n << ' ' << y2 << endl;
	}
	else {
		cout << x1 << ' ' << 0 << ' ' << x2 << ' ' << m << endl;
	}
}