#include<iostream>
#include<forward_list>
#include<fstream>
//ex 2

void Bucket_Sort(float vec[], int size)
{
	std::forward_list<float>bucket[10];
	for (int i = 0; i < size; i++) {
		int cif = vec[i] * 10;
		bucket[cif].push_front(vec[i]);
	}
	for (int i = 0; i < 10; i++) {
		bucket[i].sort();
	}
	int ok = 0;
	for (int i = 0; i < 10; i++)
		for (auto it : bucket[i])
			vec[ok++] = it;

}

int main()
{
	std::ifstream f("file.txt");
	int size;
	f >> size;
	float* vec = new float[size];
	for (int i = 0; i < size; i++) {
		f >> vec[i];
	}
	Bucket_Sort(vec, size);
	for (int i=0; i < size; i++) {
		std::cout << vec[i] << " ";
	}
	return 0;
}