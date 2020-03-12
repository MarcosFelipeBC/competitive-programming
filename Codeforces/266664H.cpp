#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
	ll a, b;
	cin >> a >> b;
	//cout << a * b << endl;
	cout << "Stable" << endl;
	if(b-a == 0LL)
	{
		cout << 0 << endl;
	}
	else 
	{
		ll pot = 1LL;
		while (pot <= b) pot *= 10LL;
		int cnt = 0;
		for (int i=0; i<20; i++){	
			if(b-a >= 0LL && (b-a)%9LL == 0LL){
				break;
			}
			cnt++;
			b += pot;
			pot *= 10LL;
		}
		int qtd = 0;
		if(cnt > 0) qtd++;
		if(b-a > 0LL) qtd++;
		cout << qtd << endl;
		if(b-a > 0LL) cout << "+ " << (b-a)/9LL << endl;
		if(cnt > 0) cout << "- " << cnt << endl;
	}
}