#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	scanf("%d", &t);
	while (t-- > 0)
	{
		char str[50];
		scanf("%s", str);
		bool dot = false;
		for (int i=0; i<strlen(str); i++) if(str[i] == '.') dot = true;
		int d, m, y;
		if(dot)
			sscanf(str, "%d.%d.%d", &d, &m, &y);
		else 
			sscanf(str, "%d/%d/%d", &m, &d, &y);
		printf("%.2d.%.2d.%.4d %.2d/%.2d/%.4d\n", d, m, y, m, d, y);
	}
}