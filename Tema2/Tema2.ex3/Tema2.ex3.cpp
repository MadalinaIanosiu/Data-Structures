#include<iostream>
#include<fstream>
#include<string>
#include <time.h> 
//ex 3

template< class T>
class Queue {
public:
	struct Node {
		T key;
		Node* next=nullptr;
		Node(T _key = NULL) {
			this->key = _key;
		}
	};
	Node* first = nullptr;
	Node* last = nullptr;
	int nr_elem = 0;
	Queue(Node* aux = nullptr) {
		if (aux != nullptr){
			first = aux;
			last = aux;
			nr_elem = 1;
		}
	}
	void push(T elem)
	{
		Node* nod = new Node(elem);
		if (nr_elem == 0) {
			last = nod;
			first = nod;
		}
		else {
			last->next = nod;
			last = nod;
		}
		nr_elem++;
	}
	void pop()
	{
		if (nr_elem == 0)
			return;
		else if (nr_elem == 1)
		{
			Node* aux = first;
			delete aux;
			first = nullptr;
			last = nullptr;
		}
		else
		{
			Node* aux = first;
			first = first->next;
			delete aux;
		}
		nr_elem--;
	}
	T front()
	{
		if (first == nullptr)
			throw;
		return first->key;
	}
	T back()
	{
		if (last == nullptr)
			throw;
		return last->key;
	}
	bool empty()
	{
		if (nr_elem == 0)
			return true;
		return false;
	}
	void clear()
	{
		if (first == nullptr)
			return;
		while (!empty())
			pop();
	}
	int size()
	{
		return nr_elem;
	}
};
void citire(Queue<std::string>& q, int & x)
{
	std::string aux;
	std::ifstream fin("fisier.txt");
	int n;
	fin >> x >> n;
	fin.get();
	x = x * 60;
	for (int i = 0; i < n; i++) {
		getline(fin, aux);
		q.push(aux);
	}
	fin.close();
}
int generateTime()
{
	return rand() % 11 + 5;
}
void afisare(Queue<std::string> q, int x)
{
	std::ofstream fout("fisier2.txt");
	while( !q.empty() && x>0 )
	{
		q.pop();
		x = x- generateTime();
	}
	while (!q.empty())
	{
		fout << q.front() << '\n';
		q.pop();
	}
	fout.close();
}
int main()
{
	srand(time(NULL));
	Queue<std::string> queue;
	int time;
	citire(queue, time);
	afisare(queue, time);
	return 0;
}