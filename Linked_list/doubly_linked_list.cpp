#include "doubly_linked_list.h"

Double_Node::Double_Node(int node_value, Double_Node *next_node, Double_Node* prev_node)
{
	value = node_value;
	next = next_node;
	prev = prev_node;
}


Double_Node* Doubly_Linked_List::get_node(int index)
{
	Double_Node *current = this->head;
	for (int i = 0; i < index; ++i)
	{
		current = current->next;
	}
	return current;
}
Doubly_Linked_List::Doubly_Linked_List()
{
	length = 0;
}

void Doubly_Linked_List::push_back(int num)
{
	Double_Node *new_node = new Double_Node(num, nullptr, nullptr);

	if (this->tail == nullptr)
	{
		this->tail = this->head = new_node;
	}
	this->tail->next = new_node;
	this->tail = new_node;
	length++;
}

void Doubly_Linked_List::add_head(int num)
{
	Double_Node *new_node = new Double_Node(num, this->head, nullptr);
	this->head = new_node;
	if (this->tail == nullptr)
	{
		this->tail = this->head;
	}
	length++;
}

void Doubly_Linked_List::erase(unsigned index)
{
	if (index == 0)
	{
		Double_Node *erased = this->head;
		this->head = this->head->next;
		delete erased;
		return;
	}
	Double_Node *prev = get_node(index - 1);
	Double_Node *erased = prev->next;
	prev->next = erased->next;
	delete erased;
	length--;
}
void Doubly_Linked_List::add(unsigned index, int num)
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
	Double_Node *prev = get_node(index - 1);
	Double_Node *new_node = new Double_Node(num, prev->next, prev);
	prev->next = new_node;
	length++;
}

unsigned Doubly_Linked_List::get_length()
{
	return length;
}

int Doubly_Linked_List::get_value(unsigned index)
{
	Double_Node *current = get_node(index);
	return current->value;
}


