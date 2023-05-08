#include "List.hpp"

int main(void) {
	List<int> list;
	list.push_front(1);
	list.push_back(2);
	list.push_back(4);
	list.insert(2, 3);
	
	list.print();
	cout << list.size() << "\n----\n";
	
	list.erase(1);
	list.print();
	cout << list.size() << "\n----\n";

	list.pop_front();	
	list.print();
	cout << list.size() << "\n----\n";
	
	list.pop_back();
	list.print();
	cout << list.size() << "\n----\n";
	
	list.clear();
	list.print();
	cout << list.size() << "\n----\n";
	// system("leaks a.out");
}