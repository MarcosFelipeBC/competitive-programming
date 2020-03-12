#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1000006;

int gcd(int a, int b) 
{ 
    if (b == 0) 
        return a; 
    return gcd(b, a % b);  
      
} 

int main(){
	ll x;
	scanf("%lld", &x);
	int divisors = 0;
	ll mn = x;
	for (ll i = 2; i*i <= x; i++){
		if(x % i == 0){
			divisors++;
			if((x * gcd(i, x/i)) == x)
				mn = min(max(i, x/i), mn);
		}
	}
	if(divisors == 0){
		printf("1 %lld\n", x);
	}
	else {
		printf("%lld %lld", x/mn, mn);
	}
}