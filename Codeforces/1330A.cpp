#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	scanf("%d", &t);
	while (t-- > 0)
	{
		int n, x;
		scanf("%d %d", &n, &x);
		bitset < 500 > vist;
		for (int i=0; i<n; i++){
			int x;
			scanf("%d", &x);
			vist[x] = 1;
		}
		int now = 1;
		while (x > 0){
			while (vist[now]){
				now++;
			}
			vist[now] = 1;
			x--;
			now++;
		}
		while (vist[now]) now++;
		if(!vist[now]) now--;
		cout << now << endl;
	}
}