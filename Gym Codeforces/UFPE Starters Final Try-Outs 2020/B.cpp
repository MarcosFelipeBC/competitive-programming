#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
int bit[N];
unordered_map < string, int > mapa;

void update(int pos, int val)
{
	for (; pos < N; pos += (pos & (-pos)))
	{
		bit[pos] += val;
	}
}

int queryInternal(int pos)
{
	int ans = 0;
	for (; pos > 0; pos -= (pos & (-pos)))
	{
		ans += bit[pos];
	}
	return ans;
}

int query(int l, int r)
{
	int ans = queryInternal(r);
	if(l) ans -= queryInternal(l-1);
	return ans;
}

int main()
{
	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	int n, m, q;
	cin >> n >> m >> q;
	vector < string > vet;
	for (int i=0; i<n; i++){
		string str;
		cin >> str;
		vet.push_back(str);
	}
	for (int i=0; i<m; i++){
		string str;
		cin >> str;
		int val;
		cin >> val;
		mapa[str] = val;
	}
	for (int i=1; i<=n; i++){
		update(i, mapa[vet[i-1]]);
	}
	while (q-- > 0)
	{
		int tp;
		cin >> tp;
		if(tp == 1)
		{
			int x;
			string str;
			cin >> x >> str;
			update(x, -query(x, x));
			update(x, mapa[str]);
		}
		else {
			int l, r;
			cin >> l >> r;
			cout << ((query(l, r) > (r-l+1)*30) ? "YES" : "NO") << endl;
		}
	}
}