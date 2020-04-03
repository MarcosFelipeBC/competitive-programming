#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
	int x, y, a, b, c;
	scanf("%d %d %d %d %d", &x, &y, &a, &b, &c);
	vector < ll > A(a), B(b), C(c);
	for (ll &x : A) scanf("%lld", &x);
	for (ll &x : B) scanf("%lld", &x);
	for (ll &x : C) scanf("%lld", &x);
	sort(A.begin(), A.end(), greater < ll >());
	sort(B.begin(), B.end(), greater < ll >());
	sort(C.begin(), C.end(), greater < ll >());
	priority_queue < ll, vector < ll >, greater < ll > > pq;
	ll sum = 0LL;
	for (int i=0; i<x; i++) {
		sum += A[i];
		pq.push(A[i]);
	}
	for (int i=0; i<y; i++) {
		sum += B[i];
		pq.push(B[i]);
	}
	int idx = 0;
	while (!pq.empty() && idx < c && pq.top() < C[idx])
	{
		sum += ll(C[idx] - pq.top());
		pq.pop();
		idx++;
	}
	printf("%lld\n", sum);
}