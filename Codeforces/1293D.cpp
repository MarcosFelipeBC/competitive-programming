#include <bits/stdc++.h>
using namespace std;

int main(){
	long long x0, y0, bx, by;
	int ax, ay;
	scanf("%lld %lld %d %d %lld %lld", &x0, &y0, &ax, &ay, &bx, &by);
	long long xs, ys, t;
	scanf("%lld %lld %lld", &xs, &ys, &t);

	vector < pair < long long, long long > > vet;
	vet.push_back({x0, y0});

	long long limit = 100000000000000000;

	for (int i=0; i<100; i++){
		if(limit/x0 < ax) break;
		x0 = ax*x0 + bx;
		if(limit/y0 < ay) break;
		y0 = ay*y0 + by;
		vet.push_back({x0, y0});
	}

	int n = vet.size();

	int ans = 0;

	for (int i=0; i<n; i++){
		int qtd = 0;
		long long sumTime = 0LL;
		long long nowx = xs, nowy = ys;
		for (int j=i; j<n; j++){
			if(sumTime + abs(vet[j].first-nowx) + abs(vet[j].second-nowy) > t) break;
			// cout << "sumTime " << j << ' ' << sumTime << endl;
			qtd++;
			sumTime += abs(vet[j].first-nowx) + abs(vet[j].second-nowy);
			nowx = vet[j].first, nowy = vet[j].second;
			ans = max(ans, qtd);
		}
		nowx = xs, nowy = ys;
		qtd = 0;
		sumTime = 0LL;
		for (int j=i; j>=0; j--){
			if(sumTime + abs(vet[j].first-nowx) + abs(vet[j].second-nowy) > t) break;
			// cout << "sumTime " << j << ' ' << sumTime << endl;
			qtd++;
			sumTime += abs(vet[j].first-nowx) + abs(vet[j].second-nowy);
			nowx = vet[j].first, nowy = vet[j].second;
			ans = max(ans, qtd); 
		}
	}

	printf("%d\n", ans);
}