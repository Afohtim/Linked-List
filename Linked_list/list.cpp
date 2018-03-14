#include "list.h"

Node::Node(int node_value, Node *next_node)
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
	length = 0;
}

void List::push_back(int num)
{
	Node *new_node = new Node(num, nullptr);

	if (this->tail == nullptr)
	{
		this->tail = this->head = new_node;
	}
	this->tail->next = new_node;
	this->tail = new_node;
	length++;
}

void List::add_head(int num)
{
	Node *new_node = new Node(num, this->head);
	this->head = new_node;
	if (this->tail == nullptr)
	{
		this->tail = this->head;
	}
	length++;
}

void List::erase(unsigned index)
{
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
	length--;
}
void List::add(unsigned index, int num)
{
	if (index > length)
	{
		throw;
	}
	if (index == 0)
	{
		this->add_head(num);
		return;
	}
	Node *prev = get_node(index - 1);
	Node *new_node = new Node(num, prev->next);
	prev->next = new_node;
	length++;
}

unsigned List::get_length()
{
	return length;
}

int List::get_value(unsigned index)
{
	Node *current = get_node(index);
	return current->value;
}


