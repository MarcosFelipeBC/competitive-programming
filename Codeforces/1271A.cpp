#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;
	if(f > e)
	{
		int mn = min(b, min(c, d));
		int ans = f*mn;
		b -= mn, c -= mn, d -= mn;
		ans += e*(min(a, d));
		cout << ans << endl;
	}
	else {
		int mn = min(a, d);
		int ans = e*mn;
		a -= mn, d -= mn;
		ans += f*(min(b, min(c, d)));
		cout << ans << endl;
	}
}