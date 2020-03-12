#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
int a[N], b[N];
bitset < N > seen;

int main(){
    int t;
    scanf("%d", &t);
    while (t-- > 0){
        int n, m;
        scanf("%d %d", &n, &m);
        for (int i=0; i<n; i++){
            scanf("%d", &a[i]);
        }
        seen.reset();
        int pos = 0;
        long long ans = 0LL, left = 0LL;
        for (int i=0; i<m; i++){
            scanf("%d", &b[i]);
            if(seen[b[i]]){
                left--;
                ans++;
            }
            else {
                for (; pos < n; pos++){
                    seen[a[pos]] = 1;
                    if(a[pos] == b[i]){
                        pos++;
                        break;
                    }
                    left++;
                }
                ans += (left*2 + 1);
            }
        }
        printf("%lld\n", ans);
    }
}