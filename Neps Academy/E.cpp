//https://neps.academy/contest/215/problem/706

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int x;
	cin >> x;
	x -= 9;
	if(x < 0) x += 24;
	cout << x << endl;
}