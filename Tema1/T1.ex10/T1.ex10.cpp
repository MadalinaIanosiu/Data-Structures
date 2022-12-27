/*10. Tipăriți sumele elementelor aflate pe pătratele concentrice ale unei matrice pătratice.
Complexitatea algoritmului este O(n^2)*/
#include <iostream>
#include <fstream>

void citire(int** mat, int dim)
{
	std::ifstream f("matrice.txt");
	for (int i = 0; i < dim; i++)
		for (int j = 0; j < dim; j++)
			f >> mat[i][j];
}
void sumaPatrate(int** mat, int dim)
{
    int c= 0;
    int sum = 0;
    while (c < dim)
    {
        for (int i = c; i < dim; i++)
            sum = sum + mat[c][i];
        for (int i = c + 1; i < dim; i++)
            sum = sum + mat[i][dim - 1];
        for (int i = dim - 2; i >= c; i--)
            sum= sum + mat[dim - 1][i];
        for (int i = dim - 2; i > c; i--)
            sum= sum + mat[i][c];
        c++;
        dim--;
        std::cout << sum << " ";
        sum = 0;
    }
    if (dim == c)
        std::cout << mat[dim][dim];
}
int main()
{
    int** matrice, dim = 0;
    std::ifstream f("matrice.txt");
    f >> dim;
    matrice = new int* [dim];
    for (int i = 0; i < dim; i++)
    {
        matrice[i] = new int[dim];
    }
    citire(matrice, dim);
    sumaPatrate(matrice, dim);
    return 0;
}

