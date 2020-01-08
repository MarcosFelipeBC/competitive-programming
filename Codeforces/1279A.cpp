#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    while (t-- > 0){
        int vet[3];
        scanf("%d %d %d", &vet[0], &vet[1], &vet[2]);
        sort(vet, vet+3);
        if(vet[0] + vet[1] >= vet[2]-1) puts("Yes");
        else puts("No");
    }
}