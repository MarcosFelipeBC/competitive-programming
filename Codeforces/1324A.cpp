#include <bits/stdc++.h>
using namespace std;

const int N = 105;
int vet[N];

int main()
{
	int t;
	scanf("%d", &t);
	while (t-- > 0)
	{
		int n;
		scanf("%d", &n);
		bool flag = true;
		int mx = -1;
		for (int i=0; i<n; i++){
			scanf("%d", &vet[i]);
			mx = max(mx, vet[i]);
		}
		for (int i=0; i<n; i++)
		{
			int x = vet[i];
			if((mx-x) & 1) flag = false;
		}
		cout << ((flag) ? "YES" : "NO") << endl;
	}
}