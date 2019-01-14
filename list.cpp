#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<assert.h>

using namespace std;

typedef int DataType;

struct ListNode
{
	DataType _data;
	ListNode* _next;
	ListNode* _prev;

	ListNode(DataType x)
		:_data(x)
		, _next(NULL)
		, _prev(NULL)
	{}
};




class List
{
	typedef ListNode Node;
public:
	List()
	{
		_head = new Node(DataType());
		_head->_next = _head;
		_head->_prev = _head;
	}

	~List()
	{
		Node* cur = _head->_next;
		while (cur != _head)
		{
			Node* next = cur->_next;
			delete cur;
			cur = next;
		}

		delete _head;
		_head = NULL;
	}

	// l2(l1)
	List(const List& l)
	{
		_head = new Node(DataType());
		_head->_next = _head;
		_head->_prev = _head;

		Node* cur = l._head->_next;
		while (cur != l._head)
		{
			this->PushBack(cur->_data);
			cur = cur->_next;
		}
	}

	// l1 = l2
	List& operator=(List l)
	{
		swap(_head, l._head);

		return *this;
	}

	void PushBack(DataType x)
	{
		Insert(_head, x);
	}

	void PopBack()
	{
		Erase(_head->_prev);
	}

	void PushFront(DataType x)
	{
		Insert(_head->_next, x);
	}

	void PopFront()
	{
		Erase(_head->_next);
	}

	// 在pos前面插入一个x
	void Insert(Node* pos, DataType x)
	{
		Node* prev = pos->_prev;
		Node* newnode = new Node(x);
		// prev newnode pos

		pos->_prev = newnode;
		newnode->_next = pos;
		prev->_next = newnode;
		newnode->_prev = prev;
	}

	void Erase(Node* pos)
	{
		assert(pos != _head);

		Node* prev = pos->_prev;
		Node* next = pos->_next;
		delete pos;
		prev->_next = next;
		next->_prev = prev;
	}

	void Print()
	{
		Node* cur = _head->_next;
		while (cur != _head)
		{
			cout << cur->_data << " ";
			cur = cur->_next;
		}
		cout << endl;
	}

	size_t Size()
	{
		size_t size;
		Node* cur = _head->_next;
		while (cur != _head)
		{
			++size;
			cur = cur->_next;
		}

		return size;
	}

	bool Empty()
	{
		return _head->_next == _head;
	}

private:
	Node* _head;
};


void TestList()
{
	List l1;
	l1.PushBack(1);
	l1.PushBack(2);
	l1.PushBack(3);
	l1.PushBack(4);

	l1.Print();

	List l2(l1);
	l2.Print();

	List l3;
	l3.PushBack(10);
	l3.PushBack(20);
	l3.PushBack(30);

	l2 = l3;
	l2.Print();
}