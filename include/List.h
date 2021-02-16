#pragma once
#include "stdio.h"
#include <iostream>


template <class ValType>
class List
{
protected:
	struct Node {
		ValType data;
		Node* next;

		Node() { 
			data = 0;
			next = NULL; 
		}
		Node(ValType temp) { 
			data = temp;
			next = NULL; 
		}
	};

	Node* head;
	int count;

public:
	class iterator
	{
	private:
		Node* current;
	public:
		iterator() { 
			current = NULL; 
		}
		iterator(Node* temp) : current(temp) {}
		iterator(const iterator& iter) { current = iter.current; }

		iterator& operator =(const iterator& iter)
		{
			if (this != &iter)
				current = iter.current;
			return *this;
		}

		iterator& operator ++()
		{
			current = current->next;
			return *this;
		}

		Node*& operator *()
		{
			return current;
		}

		Node* operator ->()
		{
			return current;
		}

		bool operator ==(iterator iter)
		{
			return (current == iter.current);
		}

		bool operator !=(iterator iter)
		{
			return (current != iter.current);
		}
	};


public:
	List()	
	{
		head = new Node();	
		head->next = head;
		count = 0;
	}
	List(ValType temp)		
	{
		head = new Node();				
		head->next = new Node(temp);	
		head->next->next = head;
		count = 1;
	}
	~List()
	{
		Node* p = head->next, * temp;
		while (p != head)
		{
			temp = p->next;
			delete p;
			p = temp;
		}
		delete head;
	}

	iterator begin() { 
		iterator temp(head->next); 
		return temp; 
	}
	iterator end() { 
		iterator temp(head); 
		return temp; 
	}

	void insert(const ValType& DataTmp, int position = 1) {
		if (position == 1)
		{
			Node* tmp = new Node(DataTmp);
			tmp->next = head->next;
			head->next = tmp;
			count++;
		}
		else if (position > 1 && position <= count + 1)
		{
			int i = 1;
			List<ValType>::iterator it = begin();
			while (i < position - 1)
			{
				++it;
				i++;
			}
			Node* tmp = new Node(DataTmp);
			tmp->next = it->next;
			it->next = tmp;
			count++;
		}
		else throw "Incorrect position";
	};

	void insert(const ValType& DataTmp, Node* position) {
		Node* tmp = new Node(DataTmp);
		tmp->next = position->next;
		position->next = tmp;
		count++;
	};

	void erase(int position) {
		if (position == 1)
		{
			Node* temp = head->next;
			head->next = temp->next;
			delete temp;
			count--;
		}
		else if (position > 1 && position <= count)
		{
			int i = 1;
			List<ValType>::iterator it = begin();
			while (i < position - 1)
			{
				++it;
				i++;
			}
			Node* temp = it->next;
			it->next = temp->next;
			delete temp;
			count--;
		}
		else throw "Incorrect position";
	};

	void erase(Node* position) {
		if (position->next != head)
		{
			Node* tmp = position->next;
			position->next = tmp->next;
			delete tmp;
			count--;
		}
		else throw "Pointer to last Node";
	};

	void Print() {
		for (List<ValType>::iterator it = begin(); it != end(); ++it)
			std::cout << it->data << std::endl;
	};

	bool search(ValType Search_Value) {
		bool flag = false;
		List<ValType>::iterator it = begin();
		while (it != end())
		{
			if (it->data == Search_Value)
			{
				flag = true;
				break;
			}
			else ++it;
		}
		return flag;
	};

	bool empty() {
		return (head->next == head);
	};

	ValType front() {
		if (!empty())
			return (head->next->data);	
		else throw "List is empty";
	};

	void clear() {
		while (!empty())
			erase(1);
		count = 0;
	};

	int GetCount() { return count; };

};
