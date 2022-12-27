//Ex 4 - 1 p 
//-complexitate: O(n)
#include<iostream>
#include<vector>
#include <algorithm> 

void max_heapify(std::vector<int>& vec, int i, int size_) 
{	int imax = i , l = (2 * i) + 1, r = (2 * i)+ 2;

	if (l < size_ && vec[l] > vec[imax])
		imax = l;

	if (r < size_ && vec[r] > vec[imax])
		imax = r;

	if (imax != i) 
	{
		std::swap(vec[i], vec[imax]);
		max_heapify(vec, imax, size_);
	}
}

void build_max_heap(std::vector<int>& vec)
{
	for (int i = (vec.size() / 2) - 1; i >= 0; i--) 
		max_heapify(vec, i, vec.size());
}

void heap_sort(std::vector<int>& vec)
{
	build_max_heap(vec);
	int sz = vec.size();
	for (int i = vec.size() - 1; i > 0; i--)
	{
		std::swap(vec[0], vec[i]);
		sz--;
		max_heapify(vec, 0, sz);
	}
}

void printVector(std::vector<int>vec, int n)
{
	for (int i = 0; i < vec.size(); i++)
		std::cout << vec[i] << " ";
	std::cout << "\n";
}

int main()
{
	std::vector<int>vec;
	int n;
	std::cout << "Size of the vector: ";
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		int k;
		std::cin >> k;
		vec.push_back(k);

	}
	heap_sort(vec);

	std::cout << "Sorted vector is: \n";
	printVector(vec, n);
}