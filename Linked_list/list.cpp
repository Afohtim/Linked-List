#include "list.h"

void swap_nodes(Node* first, Node* second)
{
	int temp = first->value;
	first->value = second->value;
	second->value = temp;
}

Node::Node(int node_value, Node *next_node = nullptr)
{
	value = node_value;
	next = next_node;
}


Node* List::get_node(int index)
{
	Node *current = this->head;
	for (int i = 0; i < index; ++i)
	{
		current = current->next;
	}
	return current;
}


List::List()
{
	this->length = 0;
}

void List::merge(List *second_list)
{
	this->tail->next = second_list->head;
}

void List::split_list(List *first_list , List *second_list)
{
	unsigned mid = this->length / 2;
	Node *temp_node = this->head;
	for (unsigned i = 0; i < this->length; ++i)
	{
		if (i <= mid)
		{
			first_list->push_back(temp_node->value);
		}
		else
		{
			second_list->push_back(temp_node->value);
		}
		temp_node = temp_node->next;
	}
}

void List::merge_lists(List *first_list, List *second_list)
{
	Node *first_node = first_list->head, *second_node = second_list->head;
	while (first_node != nullptr && second_node != nullptr)
	{
		if (first_node->value < second_node->value)
		{
			this->push_back(first_node->value);
			first_node = first_node->next;
		}
		else
		{
			this->push_back(second_node->value);
			second_node = second_node->next;
		}
	}
	if (first_node == nullptr)
		while (second_node != nullptr)
		{
			this->push_back(second_node->value);
			second_node = second_node->next;
		}
	else
	{
		while (first_node != nullptr)
		{
			this->push_back(first_node->value);
			first_node = first_node->next;
		}
	}
}

void List::sort()
{
	if (this->length == 1)
	{
		return;
	}
	if (this->length == 2)
	{
		if (this->head->value > this->tail->value)
		{
			swap_nodes(this->head, this->tail);
		}
		return;
	}

	List *first_list = new List, *second_list = new List;

	this->split_list(first_list, second_list);
	this->clear();

	first_list->sort(), second_list->sort();

	this->merge_lists(first_list, second_list);

	first_list->clear();
	delete first_list;
	second_list->clear();
	delete second_list;



}

void List::clear()
{
	while (this->length > 0)
	{
		this->pop_front();
	}
}

void List::pop_front()
{
	if (this->length == 0)
	{
		return;
	}
	Node* temp_node = this->head;
	this->head = this->head->next;
	this->length--;
	delete temp_node;
}

void List::push_back(int num)
{
	Node *new_node = new Node(num);

	if (this->length == 0)
	{
		this->tail = new_node;
		this->head = new_node;
	}
	else
	{
		this->tail->next = new_node;
		this->tail = new_node;
		
	}
	this->length++;
}

void List::push_front(int num)
{
	Node *new_node = new Node(num, this->head);
	if (this->length == 0)
	{
		this->tail = new Node(num);
		this->head = this->tail;
	}
	else
	{
		this->head = new_node;
	}
	
	this->length++;
}

void List::erase(unsigned index)
{
	if (index < 0 || index >= this->length)
	{
		throw;
	}
		
	if (index == 0)
	{
		Node *erased = this->head;
		this->head = this->head->next;
		delete erased;
		return;
	}
	Node *prev = get_node(index - 1);
	Node *erased = prev->next;
	prev->next = erased->next;
	delete erased;
	this->length--;
}
void List::add(unsigned index, int num)
{
	if (index > this->length)
	{
		throw;
	}
	if (index == 0)
	{
		this->push_front(num);
		return;
	}
	Node *prev = get_node(index - 1);
	Node *new_node = new Node(num, prev->next);
	prev->next = new_node;
	this->length++;
}

unsigned List::size()
{
	return this->length;
}

int List::get(unsigned index)
{
	if (index < 0 || index >= this->length)
		throw;
	Node *current = get_node(index);
	return current->value;
}


