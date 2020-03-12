#include <bits/stdc++.h>
using namespace std;

const int N = 5005;
int vet[N];

int main()
{
	int t;
	scanf("%d", &t);
	while (t-- > 0)
	{
		int n;
		scanf("%d", &n);
		for (int i=0; i<n; i++){
			scanf("%d", &vet[i]);
		}
		bool flag = false;
		for (int i=0; i<n; i++)
		{
			for (int j=n-1; j>i+1; j--)
			{
				if(vet[i] == vet[j]) {
					flag = true;
					break;
				}
			}
			if(flag) break;
		}
		cout << ((flag) ? "YES" : "NO") << endl;
	}
}