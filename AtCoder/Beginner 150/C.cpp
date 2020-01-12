#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int bit[N];

void update(int pos){
	for (; pos < N; pos += (pos & (-pos))){
		bit[pos]++;
	}
}

int query(int pos){
	int ans = 0;
	for (; pos > 0; pos -= (pos & (-pos))){
		ans += bit[pos];
	}
	return ans;
}

int fat(int x){
	if(x == 0) return 1;
	return x * fat(x-1);
}

int solve(vector < int >& vet){
	memset(bit, 0, sizeof bit);
	int ans = 0;
	for (int i=vet.size()-1; i>=0; i--){
		ans += fat((int)vet.size()-1-i) * query(vet[i]-1);
		update(vet[i]);
	}
	return ans;
}

int main(){
	int n;
	scanf("%d", &n);
	vector < int > v(n);
	for (int i=0; i<n; i++){
		scanf("%d", &v[i]);
	}
	int a = solve(v);
	for (int i=0; i<n; i++){
		scanf("%d", &v[i]);
	}
	int b = solve(v);
	printf("%d\n", abs(a-b));
}