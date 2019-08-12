//Problem link: https://www.hackerrank.com/contests/struct-uberhub/challenges/quem-e-o-melhor-aluno

#include <bits/stdc++.h>
using namespace std;

struct aluno {
	string nome;
	int n1, n2;
	aluno(){
		nome = "";
		n1 = n2 = 0;
	}
	aluno(string _nome, int _n1, int _n2){
		nome = _nome;
		n1 = _n1;
		n2 = _n2;
	}
	bool operator > (aluno aux) const {
		if(n1 > aux.n1) return true;
		else if(aux.n1 > n1) return false;
		else {
			if(n2 > aux.n2) return true;
			else if(aux.n2 > n2) return false;
			else {
				if(nome < aux.nome) return true;
				else return false;
			}
		}
	}
};

int main(){
	int n;
	cin >> n;
	
	aluno best;
	
	for (int i=0; i<n; i++){
		string str;
		int nota1, nota2;
		cin >> str >> nota1 >> nota2;
		aluno a = aluno(str, nota1, nota2);
		if(a > best){
			best = a;
		}
	}
	
	cout << best.nome << endl;
	cout << best.n1 << endl;
	cout << best.n2 << endl;
}
