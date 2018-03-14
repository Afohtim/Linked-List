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
	void push_back(int num);
	void add_head(int num);
	void erase(unsigned index);
	void add(unsigned index, int num);
	unsigned get_length();
	int get_value(unsigned index);


};