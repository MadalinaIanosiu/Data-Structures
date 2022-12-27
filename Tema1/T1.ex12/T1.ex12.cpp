/* Fiind dată  o matrice pătratică de dimensiuni height × width, să  se verifice pentru care dintre cele 4 zone determinate de
diagonala principală  și de cea secundară suma elementelor este maximă. 
Complexitatea algoritmului este O(n^2)*/
#include <iostream>
#include <fstream>
void Citire(int** mat, int dim)
{
	std::ifstream f("citire.txt");
	for (int i = 0; i < dim; i++)
		for (int j = 0; j < dim; j++)
			f >> mat[i][j];

} 
int Nord(int** mat, int dim)
{
	int sum = 0;
	for (int i = 0; i < dim; i++)
	{
		for (int j = 0; j < dim; j++)
			if (i < j && i + j < dim - 1)
				sum = sum + mat[i][j];
	}
	return sum;
}
int Est(int** mat, int dim)
{
	int sum = 0;
	for (int i = 0; i < dim; i++)
	{
		for (int j = 0; j < dim; j++)
			if (i < j && i + j > dim - 1)
				sum = sum + mat[i][j];
	}
	return sum;
}
int Sud(int** mat, int dim)
{
	int sum = 0;
	for (int i = 0; i < dim; i++)
	{
		for (int j = 0; j < dim; j++)
			if (i > j && i + j > dim - 1)
				sum = sum+ mat[i][j];
	}
	return sum;
}
int Vest(int** mat, int dim)
{
	int sum = 0;
	for (int i = 0; i < dim; i++)
	{
		for (int j = 0; j < dim; j++)
			if (i > j && i + j < dim - 1)
				sum = sum + mat[i][j];
	}
	return sum;
}

int main()
{
	int** mat, n;
	std::ifstream f("citire.txt");
	f >> n;
	Citire(mat, n);
	mat = new int* [n];
	int* vec = new int[4];
	for (int i = 0; i < n; i++) {
		mat[i] = new int[n];
	}
	vec[0] = Nord(mat, n);
	vec[1] = Est(mat, n);
	vec[2] = Sud(mat, n);
	vec[3] = Vest(mat, n);
	int max = 0;
	for (int i = 0; i < 4; i++)
	{
		if (vec[i] > max)
			max = vec[i];
	}
	std::cout << max;
	return 0;
}