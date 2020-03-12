#include <bits/stdc++.h>
using namespace std;

int main(){
    string str;
    cin >> str;
    int n = str.size();
    int ans = 0;
    for (int i=0; i<n/2; i++){
        if(str[i] != str[n-1-i]) ans++;
    }
    cout << ans << endl;
}