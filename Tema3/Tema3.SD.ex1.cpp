#include<iostream>
#include<list>
#include<fstream>
#include<vector>

class HashTable {
	int bucket;
	int numberKeys;
	std::list<std::pair<int, int>>* table;
public:
	HashTable(int b);
	void insertItem(std::pair<int, int> key);
	void deleteItem(int key);
	int findItem(int key);

	int hashFunction(int x) { 
		return(x % bucket);
	}

	void rehashItems();
	void displayHash();

};

HashTable::HashTable(int b)
{
	bucket = b;
	numberKeys = 0;
	table = new std::list<std::pair<int, int>>[bucket];
}

void HashTable::insertItem(std::pair<int, int> key)
{
	int index = hashFunction(key.first);
	table[index].push_back(key);
	numberKeys++;

	if ((numberKeys / bucket) >= 1.0)  
		rehashItems();
}

void HashTable::deleteItem(int key)
{
	
	int index = hashFunction(key);

	
	std::list <std::pair<int, int>> ::iterator i;
	for (i = table[index].begin(); i != table[index].end(); i++)
		if ((*i).first == key)
			break;
	
	if (i != table[index].end()) {
		table[index].erase(i);
		numberKeys--;
	}
}

int HashTable::findItem(int key)
{
	int index = hashFunction(key);
	std::list <std::pair<int, int>> ::iterator i;
	for (i = table[index].begin(); i != table[index].end(); i++)
		if (i->first == key)
			return i->second;
}

void HashTable::rehashItems()
{
	displayHash();
	auto newTable = new std::list <std::pair<int, int>>[bucket * 2];
	bucket *= 2;
	auto oldTable = table;
	table = newTable;

	numberKeys = 0;
	for (int i = 0; i < bucket / 2; i++)
		for (auto x : oldTable[i])
			insertItem(x);
}

void HashTable::displayHash()
{
	for (int i = 0; i < bucket; i++) {
		std::cout << i;
		for (auto x : table[i])
			std::cout << "-->" << "(" << x.first << ", " << x.second << ")";
		std::cout << std::endl;
	}
	std::cout << std::endl;
}
int main()
{
	HashTable h(20);
	std::ifstream f("file.txt");
	int n, key, value;
	f >> n;
	for (int i = 0; i < n; i++) {
		f >> key >> value;
		std::pair<int, int> pair = { key, value };
		h.insertItem(pair);
	}
	h.deleteItem(12);
	std::cout << "Elem cautat: " << h.findItem(8) << std::endl;
	h.displayHash();
}
