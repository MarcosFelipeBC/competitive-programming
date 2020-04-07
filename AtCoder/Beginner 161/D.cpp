//https://atcoder.jp/contests/abc161/tasks/abc161_d

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int k;
	cin >> k;
	queue < string > q;
	for (int i=1; i<=9; i++){
		string x;
		x.push_back(i+'0');
		q.push(x);
	}
	while (k > 1){
		string x = q.front();
		q.pop();
		char last = x.back() - '0';
		for (int i=max(0, last-1); i<=min(last+1, 9); i++){
			x.push_back(i+'0');
			q.push(x);
			x.pop_back();
		}
		k--;
	}
	cout << q.front() << endl;
}