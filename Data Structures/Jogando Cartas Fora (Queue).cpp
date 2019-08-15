//https://www.urionlinejudge.com.br/judge/pt/problems/view/1110
#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	while (1){
		scanf("%d", &n);
		if(n == 0) break;
		queue < int > q;
		printf("Discarded cards: ");
		for (int i=1; i<=n; i++) q.push(i);
		while (q.size() != 2){
			printf("%d, ", q.front());
			q.pop();
			int val = q.front();
			q.pop();
			q.push(val);
		}
		printf("%d\n", q.front());
		q.pop();
		printf("Remaining card: %d\n", q.front());
		q.pop();
	}
}
