/*5. Se citeste un numar natural nr si nr medii (numere reale cu doua zecimale cu valori cuprinse între 1 si 10). 
Notele se stocheaz într-un container de tip std::vector<float> note. Sa  se afiseze o statistica a mediilor astfel: 
numarul de medii cuprinse în intervalul [1, 5), numarul de medii din intervalul [5, 5.50), numarul de medii cuprinse în intervalul
[5.50, 6.50), . . ., numarul de medii cuprinse în intervalul [9.50, 10].
Complexitatea algoritmului este O(n^2)*/
#include <iostream>
#include <vector>

int main()
{
	int nr;
	std::vector<float> note;
	std::vector<int>fr = {0,0,0,0,0,0,0};
	std::cout << "Introduceti numarul de medii"<<"\n";
	std::cin >> nr;
	note.resize(nr);
	for (int i = 0; i < nr; i++) {
		std::cin >> note[i];
		if (note[i] < 5)
			fr[0]++;
		if (note[i] >= 5 && note[i] < 5.50)
			fr[1]++;
		if (note[i] >= 5.50 && note[i] < 6.50)
			fr[2]++;
		if (note[i] >= 6.50 && note[i] < 7.50)
			fr[3]++;
		if (note[i] >= 7.50 && note[i] < 8.50)
			fr[4]++;
		if (note[i] >= 8.50 && note[i] < 9.50)
			fr[5]++;
		if (note[i] >= 9.50 && note[i] <= 10)
			fr[6]++;
	}

	int ok = 0;
		if (fr[0] != 0)
			ok = 1;
		std::cout << "Avem un numar de " << fr[0] << " medii cuprinse intre [1, 5)" << std::endl;

		ok = 0;
		if (fr[1] != 0)
			ok = 1;
		std::cout << "Avem un numar de " << fr[1] << " medii cuprinse intre [5, 5.50)" << std::endl;

		ok = 0;
		if (fr[2] != 0)
			ok = 1;
		std::cout << "Avem un numar de " << fr[2] << " medii cuprinse intre [5.50, 6.50)" << std::endl;

		ok = 0;
		if (fr[3] != 0)
			ok = 1;
		std::cout << "Avem un numar de " << fr[3] << " medii cuprinse intre [6.50, 7.50)" << std::endl;

		ok = 0;
		if (fr[4] != 0)
			ok = 1;
		std::cout << "Avem un numar de " << fr[4] << " medii cuprinse intre [7.50, 8.50)" << std::endl;

		ok = 0;
		if (fr[5] != 0)
			ok = 1;
		std::cout << "Avem un numar de " << fr[5] << " medii cuprinse intre [8.50, 9.50)" << std::endl;

		ok = 0;
		if (fr[6] != 0)
			ok = 1;
		std::cout << "Avem un numar de " << fr[6] << " medii cuprinse intre [9.50, 10]" << std::endl;

	return 0;
}

