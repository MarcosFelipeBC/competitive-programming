#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, x, y;
	scanf("%d %d %d", &n, &x, &y);
	vector < pair <double, double> > dist;
	for (int i=0; i<n; i++){
		int a, b, r;
		scanf("%d %d %d", &a, &b, &r);
		dist.push_back({hypot(abs(a-x), abs(b-y)) - r, r});
	}
	sort(dist.begin(), dist.end());
	double lo = 0, hi = 10000000000, ans = .0;
	for (int i=0; i<500; i++){
		double mid = (lo + hi)*.5;
		double sz = mid;
		bool flag = true;
		for (int j=0; j<dist.size(); j++){
			if(sz < dist[j].first) {
				flag = false;
				break;
			}
			sz += dist[j].second;
		}
		if(flag) {
			ans = mid;
			hi = mid-0.00000001;
		}
		else lo = mid+0.00000001;
	}
	cout.precision(9);
	cout << fixed << ans << endl;
}