/*7. Se considera  doua  multimi de produse identificate prin numele lor de tip string, memorate în doi vectori distincti
(într-o multime fiecare element este unic!).
Sa scrie o functie care returneaza un al treilea vector, care sa contina elementele comune. Afisati vectorul rezultat. 
Complexitatea algoritmului este O(n) */
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

std::vector<std::string> Vector_Nou (std::vector<std::string>& magazin1,std::vector<std::string>& magazin2)
{
    std::vector<std::string> vectorintersectie;

    std::sort(magazin1.begin(), magazin1.end());
    std::sort(magazin2.begin(), magazin2.end());

    std::set_intersection(magazin1.begin(), magazin1.end(), magazin2.begin(), magazin2.end(), back_inserter(vectorintersectie));
    return vectorintersectie;
}
int main() 
{
    std::vector<std::string> magazin1{ "mere","pere","branza", "oua", "suc","carne"};
    std::vector<std::string> magazin2{ "oua", "capsuni","paine","carne","ciocolata"};

    auto intersectie = Vector_Nou(magazin1, magazin2);

    for (std::string n : intersectie)
        std::cout << n << ' ';

    return 0;
}