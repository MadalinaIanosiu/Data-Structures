/*6. Se citesc din fisier doua  numere foarte mari numar1 si numar2, fiecare cu mai mult de 10 cifre.
Cifrele fiecarui numar se stocheaza  într-un vector. Sa  se scrie o functie care are ca parametri acesti 2 vectori 
si returneaza  un al treilea vector, care reprezinta suma celor 2. Scrieti rezultatul pe ecran.
Complexitatea algoritmului este O(n)*/
#include<iostream>
#include<fstream>
#include<vector>

int* sum(int*& v, int*& w, int n1, int n2)
{
	int* u = new int[std::min(n1, n2) + 1];
	int tr;
	for (int i = 0; i < std::min(n1, n2); i++) {
		tr = 0;
		u[i] = (v[i] + w[i]) % 10 + tr;
		tr = (v[i] + w[i]) / 10;
	}
	return u;
}

int main()
{
	std::ifstream f("file.txt");
	long n1, n2;
	f >> n1;
	int* v = new int[n1];
	for (int i = n1 - 1; i >= 0; i--) {
		f >> v[i];
	}
	f >> n2;
	int* w = new int[n2];
	for (int i = n2 - 1; i >= 0; i--) {
		f >> w[i];
	}
	for (int i = n1 - 1; i >= 0; i--) {
		std::cout << v[i] << " ";
	}
	std::cout << std::endl;
	for (int i = n2 - 1; i >= 0; i--) {
		std::cout << w[i] << " ";
	}
	std::cout<< '\n';
	if (n1 < n2) {
		for (int i = n2 - 1; i >= n2 - n1; i--)
			v[i] = v[i - (n2 - n1)];

		for (int i = n2 - n1 - 1; i >= 0; i--)
			v[i] = 0;
	n1 = n2;
	}
	else {
		for (int i = n1 - 1; i >= n1 - n2; i--)
			w[i] = w[i - (n1 - n2)];

		for (int i = n1 - n2 - 1; i >= 0; i--)
			w[i] = 0;
	n2 = n1;
	}
	int* u = sum(v, w, n1, n2);
	 for(int i = n1 - 1; i >= 0; i--) {
		std::cout << u[i] << " ";
	}
	return 0;
}


