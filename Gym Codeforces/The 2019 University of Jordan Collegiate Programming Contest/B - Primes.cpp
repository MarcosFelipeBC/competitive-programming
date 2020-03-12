//https://codeforces.com/gym/102267/problem/B

#include <bits/stdc++.h>
using namespace std;

const int N = 10000007;
bitset < N > prime;

pair < int, int > crivo(int x){
	prime[0] = prime[1] = 0;
	for (int i=2; i<=x; i++){
		if(prime[i]){
			if(x-i <= i && prime[x-i]){
				return {x-i, i};
			}
			for (int j=i+i; j<=x; j+=i){
				prime[j] = 0;
			}
		}
	}
	return {-1, -1};
}

int main(){
	prime.set();
	int x;
	scanf("%d", &x);
	pair < int, int > resp = crivo(x);
	if(resp.first == -1) printf("-1\n");
	else printf("%d %d\n", resp.first, resp.second);
}
