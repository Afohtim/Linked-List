#include<iostream>
#include "list.h"
#include "doubly_linked_list.h"

int main()
{
	List list;
	Doubly_Linked_List list2;

	list.push_back(5);
	list2.push_back(5);
	list.add_head(1);
	list2.add_head(1);
	list.add(1, 3);
	list2.add(1, 3);

	for (unsigned i = 0; i < list.get_length(); ++i)
	{
		std::cout << list.get_value(i) << ' ';
	}
	std::cout << '\n';

	for (unsigned i = 0; i < list2.get_length(); ++i)
	{
		std::cout << list2.get_value(i) << ' ';
	}
	std::cout << '\n';

	list.erase(2);
	list2.erase(2);
	std::cout << list.get_length() << '\n';
	std::cout << list2.get_length() << '\n';
	system("pause");
}