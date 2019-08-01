#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	string str;
	cin >> str;
	string vogal = "aeiou";
	int freq_ans = 0;
	string ans = "---";
	for (int i=0; i<5; i++){
		for (int j=0; j<5; j++){
			for (int k=0; k<5; k++){
				int cont=0;
				for (int pos=0; pos+2<str.size(); pos++){
					if(str[pos] == vogal[i] && str[pos+1] == vogal[j] && str[pos+2] == vogal[k]) cont++;
				}
				if(cont >= freq_ans) {
					freq_ans = cont;
					ans[0] = vogal[i];
					ans[1] = vogal[j];
					ans[2] = vogal[k];
				}
			}
		}
	}
	cout << ans << endl;
}
