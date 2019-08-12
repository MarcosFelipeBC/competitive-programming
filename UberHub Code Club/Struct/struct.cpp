//Example code on structs

#include <bits/stdc++.h>
using namespace std;

struct pessoa {
	string nome;
	int idade;
	double altura;
	pessoa(){
		nome = "";
		idade = 0;
		altura = 0.0;
	}
	pessoa(string _nome, int _idade, double _altura){
		nome = _nome;
		idade = _idade;
		altura = _altura;
	}
	bool operator < (pessoa aux) const {
		if(altura < aux.altura) return true;
		else if(altura > aux.altura) return false;
		else {
			if(idade < aux.idade) return true;
			else if(idade > aux.idade) return false;
			else {
				if(nome < aux.nome) return true;
				else return false;
			}
		}
	}
};

int main(){
	pessoa a, b;
	a = pessoa("Amarcos", 19, 10.0);
	b = pessoa("Joao", 19, 10.0);
	if(a < b){
		cout << a.nome << endl;
	}
	else {
		cout << b.nome << endl;
	}
}
