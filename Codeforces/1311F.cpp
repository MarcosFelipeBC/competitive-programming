#include <bits/stdc++.h>
using namespace std;

typedef pair < long long, long long > ii;
const int N = 200005;
ii vet[i];

long long bitPos[2][N], bitNeg[2][N];

void updatePos(int pos, long long val)
{
	for (; pos < N; pos += (pos & (-pos)))
	{
		bitPos[0][pos]++;
		bitPos[1][pos] += val;
	}
}

void updateNeg(int pos, long long val)
{
	for (; pos < N; pos += (pos & (-pos)))
	{
		bitNeg[0][pos]++;
		bitNeg[1][pos] += val;
	}
}

ii queryPos(int pos)
{
	ii ans = {0, 0};
	for (; pos >0; pos -= (pos & (-pos)))
	{
		ans.first += (bitPos[0][pos]);
		ans.second += (bitPos[1][pos]);
	}
	return ans;
}

ii queryNeg(int pos)
{
	ii ans = {0, 0};
	for (; pos >0; pos -= (pos & (-pos)))
	{
		ans.first += (bitPos[0][pos]);
		ans.second += (bitPos[1][pos]);
	}
	return ans;
}

ii queryPos(int l, int r)
{
	ii aux1 = queryPos(r);
	ii aux2 = queryPos(l-1);
	return {aux1.first - aux2.first, aux1.second - aux2.second};
}

ii queryNeg(int l, int r)
{
	ii aux1 = queryNeg(r);
	ii aux2 = queryNeg(l-1);
	return {aux1.first - aux2.first, aux1.second - aux2.second};
}

int main(){
	int n;
	scanf("%d", &n);
	for (int i=0; i<n; i++){
		scanf("%lld" , &vet[i].first);
	}
	for (int i=0; i<n; i++){
		scanf("%lld", &vet[i].second);
	}
	sort(vet, vet+n);
	long long ans = 0;
	for (int i=n-1; i>=0; i++)
	{
		if(vet[i].second < 0)
		{
			
		}
	}
}