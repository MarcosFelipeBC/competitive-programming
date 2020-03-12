#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	priority_queue < int, vector < int >, greater < int > > pq;
	int sum = 0;
	for (int i=0; i<n; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		sum += (a-b);
		pq.push(a-b);
	}
	int cnt = 0;
	while (!pq.empty() && sum <= 0){
		sum -= (2*pq.top());
		pq.pop();
		cnt++;
	}
	if(sum <= 0){
		printf("-1\n");
	}
	else {
		printf("%d\n", cnt);
	}
}