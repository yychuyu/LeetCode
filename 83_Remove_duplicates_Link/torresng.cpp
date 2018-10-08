
/***************************************************************
*   Copyright (C) 2018 All rights reserved.
*
*   Auth     ：Torres Ng
*   Create Time ：2018/10/08
*
***************************************************************/
/**************************************************************
题目：
给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。

Example 1:
输入: 1->1->2输出: 1->2

Example 2:
输入: 1->1->2->3->3输出: 1->2->3
***************************************************************/

#include <iostream>
#include <vector>
#include <memory>
#include <initializer_list>

using namespace std;

template<typename T>
struct Node
{
	T data;
	shared_ptr<Node> next;
	Node() {
		this->data = T();
	}
	Node(T data) {
		this->data = data;
	}
};

template<typename T>
class Link
{
private:
	shared_ptr<Node<T>> head;
	shared_ptr<Node<T>> tail;
public:
	Link() {
		head = tail = new Node<T>();
	}
	Link(initializer_list<T> l) {
		head = tail = make_shared<Node<T>>();
		for(T v : l) {
			this->insertTail(v);
		}
	}

	// insert value to tail
	void insertTail(T value) {
		shared_ptr<Node<T>> node = make_shared<Node<T>>(value);
		node->next = tail->next;
		tail->next = node;
		tail = node;
	}

	bool empty() {
		return head == tail;
	}

	// remove Duplicates
	void removeDuplicates() {
		if(this->empty()) {
			return ;
		}
		
		
		shared_ptr<Node<T>> pos = head;
		T value = pos->next->data;
		pos = pos->next;
		for(shared_ptr<Node<T>> p = pos->next; p; p = p->next) {
			if(pos->data != p->data) {
				pos->next->data = p->data;
				pos = pos->next;
			}
		}
		//release node
		while(pos) {
			shared_ptr<Node<T>> p = pos->next;
			pos->next = nullptr;
			pos = p;
		}
	}

	void output() {
		shared_ptr<Node<T>> ptr = head->next;
		while(ptr) {
			cout << ptr->data;
			ptr = ptr->next;
			if(ptr) {
				cout << "->";
			}
		}
		cout << endl;
	}
};

int main(void) {
	Link<int> l = {1,1,2,3,3};
	l.removeDuplicates();
	l.output();
	return 0;
}
