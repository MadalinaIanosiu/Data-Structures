#include<iostream>
#include<fstream>
#include<list>
#include<vector>
#include<unordered_map>

std::vector<char> read()
{
	std::ifstream f("file.txt");
	std::vector<char>vec;
	int dim;
	f >> dim;
	for (int i = 0; i < dim; i++) {
		char k;
		f >> k;
		vec.push_back(k);
	}
	return vec;
}
std::unordered_map<char, int> createHashMap(std::vector<char>vec)
{
	std::unordered_map<char, int> map;
	for (auto it : vec) {
		if (map.find(it) == map.end())
			map[it] = 1; 
		else
			map[it] = map[it]++;
	}
	return map;
}
void palindrom(std::unordered_map<char, int>map)
{
	std::list<char>cuvant;
	int counter = 0;
	char cifImpara;
	for (auto it : map) {
		if (it.second % 2 == 1)
			if (counter == 0) {
				counter++;  
				cifImpara = it.second;
			}
			else {
				std::cout << "Sirul nu se poate forma";
				return;
			}
	}
	if (counter == 0) 
	{
		for (auto it : map) {
			for (int i = 0; i < (it.second) / 2; i++) {
				cuvant.push_back(it.first);
				cuvant.push_front(it.first);
			}

		}
	}
	else 
	{
		for (int i = 0; i < map[cifImpara]; i++)
			cuvant.push_back(cifImpara);
		map.erase(cifImpara); 
		for (auto it : map) {
			for (int i = 0; i < (it.second) / 2; i++) {
				cuvant.push_back(it.first);
				cuvant.push_front(it.first);
			}
		}

	}
	for (auto x : cuvant)
		std::cout << x;
}
int main()
{
	std::vector<char>vec = read();
	std::unordered_map<char, int>hashMap = createHashMap(vec);
	palindrom(hashMap);
	return 0;
}


