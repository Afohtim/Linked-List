#pragma once

struct Double_Node
{
	int value;
	Double_Node *next = nullptr;
	Double_Node *prev = nullptr;
	Double_Node(int node_value, Double_Node *next_node, Double_Node *prev_node);
};

class Doubly_Linked_List
{
private:
	Double_Node *head = nullptr, *tail = nullptr;
	unsigned length;
	Double_Node* get_node(int index);
public:
	Doubly_Linked_List();
	void push_back(int num);
	void add_head(int num);
	void erase(unsigned index);
	void add(unsigned index, int num);
	unsigned get_length();
	int get_value(unsigned index);


};