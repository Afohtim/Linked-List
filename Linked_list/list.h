#pragma once

struct Node
{
	int value;
	Node *next = nullptr;
	Node(int node_value, Node *next_node);
};

class List
{
private:
	Node *head = nullptr, *tail = nullptr;
	unsigned length;
	Node* get_node(int index);
public:
	List();
	void merge(List *tail_list);
	void sort();
	void clear();
	void push_back(int num);
	void push_front(int num);
	void pop_front();
	void erase(unsigned index);
	void add(unsigned index, int num);
	unsigned size();
	int get_value(unsigned index);


};