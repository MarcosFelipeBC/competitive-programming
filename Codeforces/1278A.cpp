#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t-->0){
        string p, h;
        cin >> p >> h;
        sort(p.begin(), p.end());
        bool flag = false;
        for (int i=0; i+p.size()<=h.size(); i++){
            string aux = h.substr(i, p.size());
            sort(aux.begin(), aux.end());
            if(p == aux){
                flag = true;
                break;
            }
        }
        puts((flag)?"YES":"NO");
    }}
