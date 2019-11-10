#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	multiset < int > s;
	int ans = 0;
	for (int i=0; i<n; i++){
		int x;
		scanf("%d", &x);
		s.insert(x);
		auto it = s.lower_bound(x);
		if(it == s.begin()) ans++;
		else {
			it--;
			s.erase(it);
		}
	}
	printf("%d\n", ans);
}
