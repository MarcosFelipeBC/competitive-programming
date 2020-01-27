#include <bits/stdc++.h>
using namespace std;

const int N = 400005;
int qtd[N];

int main(){
	int q, x;
	scanf("%d %d", &q, &x);
	int ans = 0;
	int now = 0, quant = 1;
	while (q-- > 0){
		int y;
		scanf("%d", &y);
		y%=x;
		qtd[y]++;
		while (qtd[now] >= quant){
			now++;
			if(now == x) quant++, now = 0;
			ans++;
		}
		printf("%d\n", ans);
	}
}