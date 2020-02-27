#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	scanf("%d", &t);
	while (t-- > 0){
		int n, s, k;
		scanf("%d %d %d", &n, &s, &k);
		set < int > st;
		for (int i=0; i<k; i++){
			int x;
			scanf("%d", &x);
			st.insert(x);
		}
		int ans1 = 0;
		int aux = s;
		int ans = 0;
		bool flag1 = false, flag2 = false;
		while (s <= n){
			if(st.find(s) == st.end()) {
				flag1 = true;
				break;
			}
			ans1++;
			s++;
		}
		s = aux;
		int ans2 = 0;
		while(s >= 1){
			if(st.find(s) == st.end()) {
				flag2 = true;
				break;
			}
			ans2++;
			s--;
		}
		if(flag1 == false) ans1 = 1e9;
		if(flag2 == false) ans2 = 1e9;
		ans = min(ans1, ans2);
		printf("%d\n", ans);
	}
}