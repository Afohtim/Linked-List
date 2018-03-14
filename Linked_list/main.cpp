#include<iostream>
#include "list.cpp"

int main()
{
	List list;
	list.push_back(5);
	list.add_head(1);
	list.add(1, 3);
	for (unsigned i = 0; i < list.get_length(); ++i)
	{
		std::cout << list.get_value(i) << ' ';
	}
	std::cout << '\n';
	list.erase(2);
	std::cout << list.get_length() << '\n';
	system("pause");
}