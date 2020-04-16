#include <bits/stdc++.h>
#define oo 0x3f3f3f3f3f3f3f3f
using namespace std;

long long test(int a, int b, int c){
	long long x = a-b, y = a-c, z = b-c;
	return x*x + y*y + z*z;
}

int f(int a, int b, int c){
	return abs(abs(a-c) - abs(c-b));
}

long long bb(int a, int b, vector < int > &v)
{
	int ans = -1;
	int lo = 0, hi = (int)v.size()-1;
	while (lo <= hi)
	{
		int mid = (lo + hi) >> 1;
		if(mid == v.size()-1 || f(a, b, v[mid]) <= f(a, b, v[mid+1])){
			ans = mid;
			hi = mid-1;
		}
		else {
			lo = mid+1;
			ans = mid+1;
		}
	}
	return test(a, b, v[ans]);
}

int main()
{
	int t;
	scanf("%d", &t);
	while (t-- > 0)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		vector < pair < int, int > > vet;
		for(int i=0; i<a; i++){
			int x;
			scanf("%d", &x);
			vet.push_back({x, 0});
		}
		for(int i=0; i<b; i++){
			int x;
			scanf("%d", &x);
			vet.push_back({x, 1});
		}
		for(int i=0; i<c; i++){
			int x;
			scanf("%d", &x);
			vet.push_back({x, 2});
		}
		sort(vet.begin(), vet.end());
		int last[3];
		last[0] = last[1] = last[2] = -1;
		int before = -1;
		vector < int > mid;
		long long ans = oo;
		for (int i=0; i<vet.size(); i++){
			last[vet[i].second] = vet[i].first;
			if(before != vet[i].second){
				if(last[0] != -1 && last[1] != -1 && last[2] != -1){
					int sz = (int)mid.size();
					long long mn = oo;
					if(before == 0) {
						ans = min(ans, bb(last[1], last[2], mid));
					}
					if(before == 1) {
						ans = min(ans, bb(last[0], last[2], mid));
					}
					if(before == 2) {
						ans = min(ans, bb(last[0], last[1], mid));
					}
				}
				mid.clear();
			}
			if(mid.size() == 0 || mid.back() != vet[i].first) mid.push_back(vet[i].first);
			before = vet[i].second;
		}
		printf("%lld\n", ans);
	}
}