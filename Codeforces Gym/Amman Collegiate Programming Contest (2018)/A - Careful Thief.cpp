//https://codeforces.com/gym/101810/problem/A

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int M = 100005;
pair < pair < int, int >, ll > vet[M];
ll partialSum[M];

ll solve1(int m, int k){
	ll ans = 0LL;
	for (int i=0; i<m; i++){
		ll partialAns = 0;
		int lo = 0, hi = i, resp = -1;
		int lost = max(vet[i].first.second - k+1, 1);
		while (lo <= hi){
			int mid = (lo + hi) >> 1;
			if(vet[mid].first.first <= lost && vet[mid].first.second >= lost) {
				resp = mid;
				break;
			}
			else if(vet[mid].first.first > lost){
				resp = mid;
				hi = mid-1;
			}
			else {
				lo = mid+1;
			}
		}
		if(vet[resp].first.first <= lost && vet[resp].first.second >= lost) {
			partialAns = partialSum[i] - partialSum[resp];
			partialAns += (vet[resp].second * (long long)(vet[resp].first.second - lost+1));
		}
		if(vet[resp].first.first > lost){
			partialAns = partialSum[i] - ((resp-1 >= 0) ? partialSum[resp-1] : 0);
		}
		ans = max(ans, partialAns);
	}
	return ans;
}

ll solve2(int m, int k){
	ll ans = 0LL;
	for (int i=0; i<m; i++){
		ll partialAns = 0;
		int lo = i, hi = m-1, resp = -1;
		int lost = min(1000000000, vet[i].first.first+k-1);
		while (lo <= hi){
			int mid = (lo + hi) >> 1;
			if(vet[mid].first.first <= lost && vet[mid].first.second >= lost){
				resp = mid;
				break;
			}
			else if(vet[mid].first.second < lost){
				resp = mid;
				lo = mid+1;
			}
			else {
				hi = mid-1;
			}
		}
		if(vet[resp].first.first <= lost && vet[resp].first.second >= lost){
			partialAns = ((resp-1 >= 0) ? partialSum[resp-1] : 0) - ((i-1 >= 0) ? partialSum[i-1] : 0);
			partialAns += (vet[resp].second * (long long)(lost - vet[resp].first.first+1));
		}
		if(vet[resp].first.second < lost){
			partialAns = partialSum[resp] - ((i-1 >= 0) ? partialSum[i-1] : 0);
		}
		ans = max(ans, partialAns);
	}
	return ans;
}

int main(){
	int t;
	scanf("%d", &t);
	while (t-- > 0){
		int m, k;
		scanf("%d %d", &m, &k);
		for (int i=0; i<m; i++){
			scanf("%d %d %lld", &vet[i].first.first, &vet[i].first.second, &vet[i].second);
		}
		sort(vet, vet+m);
		for (int i=0; i<m; i++) {
			partialSum[i] = vet[i].second * (long long)(vet[i].first.second - vet[i].first.first + 1);
			if(i) partialSum[i] += partialSum[i-1];
		}
		printf("%lld\n", max(solve1(m, k), solve2(m, k)));
	}
}
