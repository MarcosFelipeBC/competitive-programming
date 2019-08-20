#include <bits/stdc++.h>
#define oo 0x3f3f3f3f
using namespace std;

const int N = 105;
const int M = 1000006;
string mat[N];
int p[M], dist[N][N];

int main(){
	int n;
	cin >> n;
	for (int i=0; i<n; i++){
		cin >> mat[i];
	}
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			dist[i][j] = (mat[i][j] == '1') ? 1 : oo;
			if(i == j) dist[i][j] = 0;
		}
	}
	for (int k=0; k<n; k++){
		for (int i=0; i<n; i++){
			for (int j=0; j<n; j++){
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	int m;
	cin >> m;
	for (int i=0; i<m; i++){
		cin >> p[i];
		p[i]--;
	}	
	int last = 0;
	vector < int > ans;
	ans.push_back(p[last]);
	for (int i=1; i<m-1; i++){
		if(dist[p[last]][p[i]] != i - last){
			last = i-1;
			ans.push_back(p[i-1]);
		}
	}
	if(dist[p[last]][p[m-1]] < m-1 - last){
		ans.push_back(p[m-2]);
	}
	ans.push_back(p[m-1]);
	cout << ans.size() << endl;
	for (int i=0; i<ans.size(); i++){
		cout << ans[i]+1 << ' ';
	}
	puts("");
}
