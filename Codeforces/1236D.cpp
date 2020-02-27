#include <bits/stdc++.h>
#define oo 0x3f3f3f3f
using namespace std;

const int N = 100005;

set < int > row[N], col[N];

int main(){
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	for (int i=1; i<=n; i++){
		row[i].insert(0);
		row[i].insert(m+1);
	}
	for (int i=1; i<=m; i++){
		col[i].insert(0);
		col[i].insert(n+1);
	}
	for (int i=0; i<k; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		row[x].insert(y);
		col[y].insert(x);
	}
	long long walked = 1LL;
	int x = 1, y = 1;
	col[1].insert(1);
	while (1)
	{
		int Y = *(row[x].upper_bound(y));
		if(Y == y+1) break;
		walked += ((Y-1) - y);
		y = Y-1;
		row[x].insert(y);
		col[y].insert(x);
		// cout << "1" << endl;
		cout << x << ' ' << y << ' ' << walked << endl;

		int X = *(col[y].upper_bound(x));
		if(X == x+1) break;
		walked += ((X-1) - x);
		x = X-1;
		row[x].insert(y);
		col[y].insert(x);
		// cout << "2" << endl;
		cout << x << ' ' << y << ' ' << walked << endl;

		Y = *(prev(row[x].lower_bound(y)));
		if(Y == y-1) break;
		walked += (y - (Y+1));
		y = Y+1;
		row[x].insert(y);
		col[y].insert(x);
		// cout << "3" << endl;
		cout << x << ' ' << y << ' ' << walked << endl;

		X = *(prev(col[y].lower_bound(x)));
		if(X == x-1) break;
		walked += (x - (X+1));
		x = X+1;
		row[x].insert(y);
		col[y].insert(x);
		// cout << "4" << endl;
		cout << x << ' ' << y << ' ' << walked << endl;

	}
	cout << ((walked == (long long)n*(long long)m - (long long)k) ? "Yes" : "No") << ' ' << walked <<endl;
}