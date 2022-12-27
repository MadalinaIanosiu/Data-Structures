//Ex 4 - Concurenti -1p
#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <string>
#include<unordered_map>

void read(std::vector<std::list<std::string>>& competitors, int& noSports)
{
	std::ifstream f("file.txt");
	int noCompetitors; 
	std::string name;
	f >> noSports; 
	competitors.resize(noSports);
	for (int i = 0; i < noSports; i++)
	{
		f >> noCompetitors;
		for (int j = 0; j < noCompetitors; j++)
		{
			f >> name;
			competitors[i].push_back(name);
		}
	}
}
void detectMultipleCompetitors(std::vector<std::list<std::string>> competitors, int noSports)
{
	std::unordered_map<std::string, int>map;
	for (int i = 0; i < noSports; i++)
	{
		for (auto it = competitors[i].begin(); it != competitors[i].end(); it++)
		{
			std::unordered_map<std::string, int>::iterator a = map.find(*it);
			if (a == map.end())
				map[*it] = 1;
			else
				a->second++;
		}
	}
	for (auto it = map.begin(); it != map.end(); it++)
	{
		if (it->second != 1) {
			std::cout << it->first << " ";
		}
	}
}
int main()
{
	std::vector<std::list<std::string>> competitors;
	int noSports;
	read(competitors, noSports);
	detectMultipleCompetitors(competitors, noSports);
	return 0;
}