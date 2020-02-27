#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	scanf("%d", &t);
	while (t-- > 0)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		int ans = a+b+c;
		int na, nb, nc;
		na = nb = nc = 0;
		for (int i=1; i<30003; i++){
			int aux = 0;
			int bb = i;
			aux += abs(bb - b);
			int aa = -1;
			for (int j=1; j*j<=i; j++){
				if(i%j == 0){
					if(aa == -1 || abs(aa-a) > abs(j-a)) aa = j;
					if(aa == -1 || abs(aa-a) > abs(i/j - a)) aa = i/j;
				}
			}
			int cc = c;
			aux += abs(aa - a);
			if(cc%bb != 0){
				int d = round(double(cc)/bb);
				cc = d*bb;
			}
			aux += abs(cc - c);
			if(aux < ans)
			{
				ans = aux;
				na = aa, nb = bb, nc = cc;
			}
		}
		printf("%d\n%d %d %d\n", ans, na, nb, nc);
	}
}