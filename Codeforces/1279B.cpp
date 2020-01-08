#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    while (t-- > 0){
        int n, s;
        scanf("%d %d", &n, &s);
        int mx = 0, ans = 0, mx_id;
        long long sum = 0LL;
        for (int i=0; i<n; i++){
            int x;
            scanf("%d", &x);
            sum += (long long)x;
            if(sum <= s){
                ans = 0;           
            }
            else if(sum - mx <= s) {
                ans = mx_id;
            }
            if(mx < x){
                mx = x;
                mx_id = i+1;
            }
        }
        printf("%d\n", ans);
    }
}