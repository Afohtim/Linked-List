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
	void split_list(List *first_list, List *second_list);
	void merge_lists(List *first_list, List *second_list);
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
	int get(unsigned index);


};