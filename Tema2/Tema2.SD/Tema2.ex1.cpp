#include<iostream>
#include<list>
struct node {
	int key;
	node* previos, * next;
};
struct list {
	node* first = nullptr;
	node* last = nullptr;
	int size = 0;

	void push_front(int x)
	{
		node* new_node = new node;
		new_node->key = x;
		new_node->previos = nullptr;
		if (first != nullptr) {
			new_node->next = first;
			first->previos = new_node;
		}
		else {

			new_node->next = nullptr;
			last = new_node;
		}
		first = new_node;
		size++;
	}
	void push_back(int x)
	{
		node* new_node = new node;
		new_node->key = x;
		new_node->next = nullptr;
		new_node->previos = last;
		if (size != 0)
			last->next = new_node;
		else
			first = new_node;
		last = new_node;
		size++;
	}
	void pop_front() {
		if (size == 1)first = last = nullptr;
		else {
			first = first->next;
			delete first->previos;
			first->previos = nullptr;
			size--;
		}
	}
	void pop_back()
	{
		if (size == 1)
			first = last = nullptr;
		else {
			last = last->previos;
			delete last->next;
			last->next = nullptr;
			size--;
		}
	}
	node* find(int x)
	{
		node* current = new node;
		current = first;
		while (current != NULL && current->key != x)
		{
			current = current->next;
		}
		return current;
	}
	void erase(node* Nod)
	{
		if (Nod->previos == nullptr)
			pop_front();
		else if (Nod->next == nullptr)
			pop_back();
		else
		{
			Nod->previos->next = Nod->next;
			Nod->next->previos = Nod->previos;
			delete Nod;
		}
		size--;
	}
	void remove(int x)
	{
		node* Nod = new node;
		Nod = first;
		while (Nod != nullptr)
		{
			if (Nod->key == x)
			{
				if (size == 1) {
					first = last = nullptr;
					Nod = Nod->next;
				}
				else if (Nod->previos == nullptr) {
					Nod = Nod->next;
					pop_front();
				}
				else if (Nod->next == nullptr) {
					Nod = Nod->next;
					pop_back();
				}
				else {
					Nod = Nod->next;
					erase(Nod->previos);
				}
			}
			else Nod = Nod->next;
		}
	}
	void insert(node* Nod, int x)
	{
		if (Nod->previos == nullptr)push_front(x);
		else {
			node* new_node = new node;
			new_node->key = x;
			new_node->previos = Nod->previos;
			new_node->next = Nod;
			Nod->previos->next = new_node;
			Nod->previos = new_node;
			size++;
		}
	}
	bool empty()
	{
		if (size == 0)return false;
		else return true;
	}
	void print()
	{
		node* current = new node;
		current = first;
		while (current != nullptr)
		{
			std::cout << current->key << " ";
			current = current->next;
		}
		std::cout << '\n';
	}
	void clear()
	{
		if (first == nullptr)return;
		else if (first->next->next == nullptr)
			delete first->next;
		else {
			node* current = new node;
			current = first->next->next;
			while (current != nullptr)
			{
				delete current->previos;
				if (current->next == nullptr)current = nullptr;
				else current = current->next;
			}
		}
		first = last = nullptr;
	}
};
struct Queue {
	struct nodQ {
		int key;
		nodQ* next;
	};
	nodQ* first, * last;
	int nr_elem = 0;
	Queue()
	{
		first = nullptr;
		last = nullptr;
	}
	void push(int x)
	{
		nodQ* nod = new nodQ;
		nod->key = x;
		nod->next = nullptr;
		if (last == nullptr)first = last = nod;
		else {
			last->next = nod;
			last = nod;
		}
		nr_elem++;
	}
	void pop()
	{
		if (first == nullptr)return;
		nodQ* aux = first;
		first = first->next;
		delete aux;
		nr_elem--;
	}
	void print()
	{
		nodQ* tmp = first;
		while (tmp != nullptr)
		{
			std::cout << tmp->key << "  ";
			tmp = tmp->next;
		}
	}
	void clear()
	{
		while (first != nullptr)
		{
			pop();
		}
	}
	nodQ* front()
	{
		return first;
	}
	nodQ* back()
	{
		return last;
	}
	bool empty()
	{
		if (first == nullptr)return true;
		return false;
	}
	int size()
	{
		return nr_elem;
	}
};
bool palindrom(list l)//verifica daca o lista este palindrom
{
	node* i = new node;
	node* j = new node;
	i = l.first;
	j = l.last;
	if (l.size % 2 == 0)
	{
		while (j->next != i) {
			if (i->key != j->key)return false;
			else {
				i = i->next;
				j = j->previos;
			}
		}

	}
	else {
		while (i != j)
			if (i->key != j->key)return false;
			else {
				i = i->next;
				j = j->previos;
			}
	}
	return true;
}
bool compar(list l1, list l2)
{
	if (l1.size != l2.size)return false;
	else {
		node* i = new node;
		node* j = new node;
		i = l1.first;
		j = l2.first;
		while (i != nullptr)
		{
			if (i->key != j->key)return false;
			i = i->next;
			j = j->next;
		}
	}
	return true;
}
int main()
{
	list l;
	l.push_back(2);
	l.push_back(2);
	l.push_back(3);
	l.push_back(2);
	l.erase(l.first);
	l.print();
	std::cout << "--------------------------" << '\n';
	int options, value;
	do {
		std::cin >> options;
		switch (options)
		{
		case 1:
			std::cin >> value;
			l.push_front(value);
			l.print();
			break;
		case 2:
			std::cin >> value;
			l.push_back(value);
			l.print();
			break;
		case 3:
			l.pop_front();
			l.print();
			break;
		case 4:
			l.pop_back();
			l.print();
			break;
		case 5:
			std::cin >> value;
			if (l.find(value) != nullptr)std::cout << "DA" << '\n';
			else std::cout << "NU" << '\n';
			break;
		case 6:
			std::cin >> value;
			l.remove(value);
			l.print();
			break;
		case 7:
			l.print();
			break;
		case 8:
			l.clear();
			l.print();
			break;
		default:
			std::cout << "This option does not exist";
			break;
		}
	} while (options != 0);
	return 0;
}