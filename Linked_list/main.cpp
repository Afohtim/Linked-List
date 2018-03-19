#include<iostream>
#include<string>
#include "list.h"
#include "doubly_linked_list.h"


int main()
{
	List list;
	std::string help = "Available commands: \npush_back x \npush_front x \npop_front \nget i \nsort \nclear \nerase i \nwhere x - value, i - index\n";
	while (true)
	{
		int x;
		std::string message;
		std::cin >> message;
		if (message == "push_back")
		{
			int x;
			std::cin >> x;
			list.push_back(x);
		}
		else if (message == "push_front")
		{
			int x;
			std::cin >> x;
			list.push_front(x);
		}
		else if (message == "pop_front")
		{
			list.pop_front();
		}
		else if (message == "get")
		{
			int i;
			std::cin >> i;
			try
			{
				std::cout << list.get(i) << '\n';
			}
			catch (const std::exception& e)
			{
				std::cout << " Wrong index\n";
			}
			
		}
		else if (message == "clear")
		{
			list.clear();
		}
		else if(message == "erase")
		{
			int i;
			std::cin >> i;
			try
			{
				list.erase(i);
			}
			catch(const std::exception&)
			{
				std::cout << " Wrong index\n";
			}
		}
		else if(message == "size")
		{
			std::cout << list.size();
		}
		else if (message == "sort")
		{
			list.sort();
		}
		else if(message == "help")
		{
			std::cout << help;
		}
		else if (message == "end")
		{
			break;
		}
	}
	return 0;

}