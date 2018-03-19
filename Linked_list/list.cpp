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
	this->length = 0;
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
	this->length++;
}

void List::push_front(int num)
{
	Node *new_node = new Node(num, this->head);
	this->head = new_node;
	if (this->tail == nullptr)
	{
		this->tail = this->head;
	}
	this->length++;
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

int List::get_value(unsigned index)
{
	Node *current = get_node(index);
	return current->value;
}


