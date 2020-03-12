#include <bits/stdc++.h>
using namespace std;

map < int, int > seen;

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	queue < int > q;
	for (int i=0; i<n; i++){
		int x;
		scanf("%d", &x);
		seen[x] = 0;
		q.push(x);
	}
	vector < int > ans;
	long long sum = 0LL;
	while (ans.size() != m && !q.empty()){
		int x = q.front();
		q.pop();
		if(!seen.count(x-1)){
			q.push(x-1);
			seen[x-1] = seen[x]+1;
			sum += seen[x-1];
			ans.push_back(x-1);
		}
		if(ans.size() == m) break;
		if(!seen.count(x+1)){
			q.push(x+1);
			seen[x+1] = seen[x]+1;
			sum += seen[x+1];
			ans.push_back(x+1);
		}
	}
	printf("%lld\n", sum);
	for (int i=0; i<ans.size(); i++) printf("%d ", ans[i]);
	puts("");
}