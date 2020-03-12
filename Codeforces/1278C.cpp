#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
int vet[N];
map < int, int > saved;

int main(){
    int t;
    scanf("%d", &t);
    while (t-- > 0){
        int n;
        scanf("%d", &n);
        int ans = 2*n;
        int a = 0, b = 0;
        for (int i=0; i<2*n; i++){
            scanf("%d", &vet[i]);
            if(vet[i] == 1) a++;
            else b++;
        }
        int dif = a-b;
        if(dif == 0) ans = 0;
        // cout << dif << endl;
        int A = 0, B = 0;
        for (int i=n; i<n+n; i++){
            if(vet[i] == 1) A++;
            else B++;
            if(saved.count(A-B)) saved[A-B] = min(saved[A-B], i-n+1);
            else saved[A-B] = i-n+1;
            if(A-B == dif) ans = min(ans, i-n+1);
            // cout << A-B << ' ' << i-n+1 << endl;
        }
        // puts("-----");
        A=0, B=0;
        for (int i=n-1; i>=0; i--){
            if(vet[i] == 1) A++;
            else B++;
            // cout << (dif-(A-B)) << endl;
            if(A-B == dif) ans = min(ans, (n-1-i+1));
            if(saved.count((dif-(A-B)))){
                // cout << "ans: " << ans << endl;
                ans = min(ans, ((n-1)-i+1) + saved[(dif-(A-B))]);
            }
        }
        saved.clear();
        printf("%d\n", ans);
    }
}