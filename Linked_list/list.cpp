

struct Node
{
	int value;
	Node *next = nullptr;
	Node(int node_value, Node *next_node)
	{
		value = node_value;
		next = next_node;
	}
};

class List
{
private:
	Node *head = nullptr, *tail = nullptr;
	unsigned length;
	Node* get_node(int index)
	{
		Node *current = head;
		for (int i = 0; i < index; ++i)
		{
			current = current->next;
		}
		return current;
	}
public:
	List()
	{
		length = 0;
	}

	void push_back(int num)
	{
		Node *new_node = new Node(num, nullptr);

		if (tail == nullptr)
		{
			tail = head = new_node;
		}
		tail->next = new_node;
		tail = new_node;
		length++;
	}

	void add_head(int num)
	{
		Node *new_node = new Node(num, head);
		head = new_node;
		if (tail == nullptr)
		{
			tail = head;
		}
		length++;
	}

	void erase(unsigned index)
	{
		if (index == 0)
		{
			Node *erased = head;
			head = head->next;
			delete erased;
			return;
		}
		Node *prev = get_node(index - 1);
		Node *erased = prev->next;
		prev->next = erased->next;
		delete erased;
		length--;
	}
	void add(unsigned index, int num)
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

	unsigned get_length()
	{
		return length;
	}

	int get_value(unsigned index)
	{
		Node *current = get_node(index);
		return current->value;
	}


};