#include <bits/stdc++.h>
using namespace std;

const int N = 15;

struct player{
	int curinga;
	int freqCards[N];
	player(){
		curinga = 0;
		memset(freqCards, 0, sizeof freqCards);
	}
}vet[N];

int mapping(char c){
	if(c == 'A') return 1;
	if(c >= '2' && c <= '9') return c-'0';
	if(c == 'D') return 10;
	if(c == 'Q') return 11;
	if(c == 'J') return 12;
	if(c == 'K') return 13;
}

bool won(int idx){
	for (int i=1; i<=13; i++){
		if(vet[idx].freqCards[i] == 4) return true;
	}
	return false;
}

int main(){
	int n, k;
	cin >> n >> k;
	k--;
	bool flag = false;
	for (int i=0; i<n; i++){
		string str;
		cin >> str;
		for (int j=0; j<str.size(); j++){
			vet[i].freqCards[mapping(str[j])]++;
		}
	}
	for (int i=0; i<n; i++){
		if(i != k && won(i)){
			printf("%d\n", i+1);
			return 0;
		}
	}
	vet[k].curinga = 1;
	for (int now = k; now < n; now = (now + 1)%n){
		if(vet[now].curinga == 2) {
			vet[now].curinga = 0;
			vet[(now+1)%n].curinga = 1;
		}
		else {
			if(vet[now].curinga == 1) vet[now].curinga = 2;
			int mn = -1;
			for (int i=1; i<=13; i++){
				if(vet[now].freqCards[i] != 0 && (mn == -1 || vet[now].freqCards[i] < vet[now].freqCards[mn])) mn = i;				
			}
			vet[now].freqCards[mn]--;
			vet[(now+1)%n].freqCards[mn]++;
		}
		if(won(now)) {
			printf("%d\n", now+1);
			return 0;
		}
	}
	return 0;
}
