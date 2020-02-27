#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 500005;

int main()
{
	int t;
	scanf("%d", &t);
	while (t-- > 0)
	{
		ll n, g, b;
		cin >> n >> g >> b;
		ll half = n/2LL + (n&1);
		ll qtd = half/g;
		if(g >= half) {
			cout << n << endl;
			continue ;
		}
		if(half%g != 0){
			cout << max(n, (qtd * (g+b)) + half%g) << endl;
		}
		else {	
			qtd--;
			cout << max(n, (qtd * (g+b)) + g) << endl;
		}
	}
}
