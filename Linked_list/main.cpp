#include<iostream>
#include "list.h"
#include "doubly_linked_list.h"

int main()
{
	List list;
	Doubly_Linked_List list2;

	list.push_back(5);
	list2.push_back(5);
	list.push_front(9);
	list2.push_front(1);
	list.add(1, 2);
	list2.add(1, 3);
	list.sort();

	for (unsigned i = 0; i < list.size(); ++i)
	{
		std::cout << list.get_value(i) << ' ';
	}
	std::cout << '\n';

	for (unsigned i = 0; i < list2.size(); ++i)
	{
		std::cout << list2.get_value(i) << ' ';
	}
	std::cout << '\n';

	list.erase(2);
	list2.erase(2);
	std::cout << list.size() << '\n';
	std::cout << list2.size() << '\n';
	system("pause");
}