#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
int group[N], gp, n, m;
int hasConnection[N];
vector < pair < int, int > > edges;

bool build(int x){
	++gp;
	memset(hasConnection, 0, sizeof hasConnection);
	for (int i=0; i<m; i++){
		if(edges[i].first == x){
			hasConnection[edges[i].second] = 1;
		}
		else if(edges[i].second == x){
			hasConnection[edges[i].first] = 1;
		}
	}
	for (int i=1; i<=n; i++){
		if(!hasConnection[i]){
			if(group[i] != 0) return false;
			group[i] = gp;
		}
	}
	return true;
}

int main(){
	scanf("%d %d", &n, &m);
	for (int i=0; i<m; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		edges.push_back({a, b});
	}
	int now = 1;
	gp = 0;
	if(!build(now)){
		printf("-1\n");
		return 0;
	}
	bool flag = false;
	for (int i=1; i<=n; i++){
		if(group[i] == 0) {
			now = i;
			flag = true;
			break;
		}
	}
	if(flag == false) {
		printf("-1\n");
		return 0;
	}
	flag = false;
	if(!build(now)){
		printf("-1\n");
		return 0;
	}
	for (int i=1; i<=n; i++){
		if(group[i] == 0){
			now = i;
			flag = true;
			break;
		}
	}
	if(flag == false) {
		printf("-1\n");
		return 0;
	}
	if(!build(now)){
		printf("-1\n");
		return 0;
	}
	for (int i=1; i<=n; i++){
		if(group[i] == 0) {
			printf("-1\n");
			return 0;
		}
	}
	int a = 0, b = 0, c = 0; 
	for (int i=1; i<=n; i++) {
		if(group[i] == 1) a++;
		if(group[i] == 2) b++;
		if(group[i] == 3) c++;
	}
	for (int i=0; i<m; i++){
		if(group[edges[i].first] == group[edges[i].second]) {
			printf("-1\n");
			return 0;
		}
	}
	if(a == 0 || b == 0 || c == 0) {
		printf("-1\n");
		return 0;
	}
	for (int i=1; i<=n; i++){
		if(i != 1) printf(" ");
		printf("%d", group[i]);
	}
	printf("\n");
}