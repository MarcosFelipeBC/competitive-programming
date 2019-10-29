//https://codeforces.com/gym/102267/problem/I

#include <bits/stdc++.h>
using namespace std;

const int N = 150005;
int ans[N];

int main(){
	int n;
	cin >> n;
	stack < int > st;
	string str;
	cin >> str;
	string aux;
	for (int i=0 ;i<str.size(); i++){
		if(str[i] >= '0' && str[i] <= '9'){
			aux.push_back(str[i]);
		}
		else {
			if(aux.size() != 0){
				if(!st.empty()) ans[atoi(aux.c_str())] = st.top();
				st.push(atoi(aux.c_str()));
				aux.clear();
			}
		}
		if(str[i] == ')') st.pop();
	}
	for (int i=1; i<=n; i++){
		if(i != 1) printf(" ");
		printf("%d", ans[i]);
	}
	puts("");
}
