#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    while (t-- > 0){
        int a, b;
        scanf("%d %d", &a, &b);
        int dif = abs(a-b);
        int val = 1;
        int extra = 0;
        for  (val=1; ; val++){
            if(dif <= 0) {
                extra = -dif;
                break;
            }
            dif -= val;
        }
        while(extra & 1){
            extra += val;
            val++; 
        }
        printf("%d\n", val-1);
    }

}