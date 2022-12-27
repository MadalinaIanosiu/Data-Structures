//Ex 3 - 4 p
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<queue>

struct Nod {
	std::string nume;
	int nrCopii;
	int nivel;
	Nod* tata;
	std::vector<Nod*> copii;
	Nod()
	{
		nume = ' ';
		nrCopii = 0;
		nivel = 0;
		tata = nullptr;
	}
};
class arbore{

public:
	Nod* radacina;
	int nivelMax;
	arbore()
	{
		radacina = nullptr;
		nivelMax = 0;
	}
	Nod* cautareNume(std::string nume);
	void citire();
	void afisareArbore(std::string spatiu, Nod* nod_curent, bool ultim);
	void afisarePersoana(std::string nume);
};

Nod* arbore::cautareNume(std::string nume)
{
	std::queue<Nod*> q;
	q.push(radacina);
	while (!q.empty())
	{
		Nod* aux = q.front(); 
		q.pop();
		if (aux->nume == nume)
			return aux; 
		for (int i = 0; i < aux->nrCopii; i++)
			q.push(aux->copii[i]);
	}
	return nullptr;
}

void arbore::citire()
{
	std::ifstream f("nume.txt");

	int nr_pers;
	f >> nr_pers;
	radacina = new Nod;
	f >> radacina->nume;
	radacina->nivel = 1;
	nivelMax = 1;

	for (int i = 0; i < nr_pers - 1; i++)
	{
		std::string nume, nume_parinte;
		f >> nume >> nume_parinte;
		Nod* parinte = cautareNume(nume_parinte);
		Nod* copil = new Nod;
		copil->nume = nume;
		copil->tata = parinte;
		parinte->nrCopii++;
		parinte->copii.push_back(copil);

		copil->nivel = parinte->nivel + 1;
		if (copil->nivel > nivelMax)
			nivelMax = copil->nivel;
	}
}
void arbore::afisareArbore(std::string spatiu, Nod* nod_curent, bool ultim)
{
	if (nod_curent != nullptr) {
		std::cout << spatiu;
		if (!ultim)
			std::cout << "|--";
		else
			std::cout << "`--";
		if (nod_curent->tata != nullptr)
			std::cout << nod_curent->nume << ", " << nod_curent->tata->nume << ", " << nod_curent->nrCopii << std::endl;
		else
			std::cout << nod_curent->nume << ", " << "nil" << ", " << nod_curent->nrCopii << std::endl;
		for (int i = 0; i < nod_curent->nrCopii; i++)
			if (i == nod_curent->nrCopii - 1)
				afisareArbore(spatiu + (!ultim ? " | " : "     "), nod_curent->copii[i], true);
			else
				afisareArbore(spatiu + (!ultim ? "|    " : "     "), nod_curent->copii[i], false);
	}
}

void arbore::afisarePersoana(std::string nume)
{
	Nod* persoana = cautareNume(nume);
	if (persoana != nullptr) {
		std::cout << "Persoana cautata este:" << nume << std::endl;
		std::cout << "Parintele lui " << nume << " este " << persoana->tata->nume << std::endl;
		std::cout << "Copiii lui " << nume << " sunt: ";
		for (int i = 0; i < persoana->nrCopii; i++)
			std::cout << persoana->copii[i]->nume << ", ";
		std::cout << std::endl;
	}
	else
		std::cout << "Persoana cautata nu exista" << std::endl;
}
int main()
{
	arbore genealogic;
	genealogic.citire();
	genealogic.afisareArbore("", genealogic.radacina, true);
	genealogic.afisarePersoana("Alex");
	std::cout << "Numarul de generatii este " << genealogic.nivelMax;
}


