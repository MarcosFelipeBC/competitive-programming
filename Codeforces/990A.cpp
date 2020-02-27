#include <bits/stdc++.h>
using namespace std;

int main(){
	long long n, m;
	long long a, b;
	cin >> n >> m >> a >> b;
	if (n%m == 0)
	{
		cout << 0 << endl;
	}
	else {
		long long x = n/m;
		long long y = x + 1;
		cout << min(abs(x*m-n)*b, abs(y*m-n)*a) << endl;
	}
}