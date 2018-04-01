#pragma once
#include <cassert>
#include <iostream>
using namespace std;
template<typename T>class Stack;
template<typename T>class Node {
	T info;
	Node <T>*link;
public:
	Node(T data = 0, Node <T>*next = nullptr) {
		info = data;
		link = next;
	}
	friend class Stack<T>;
};
template <typename T>class Stack {
	Node <T>*top;
public:
	Stack() { top = nullptr; }
	~Stack();
	void Push(const T &data);
	T Pop();
	T GetTop();
	void MakeEmpty();
	bool IsEmpty() { return top == nullptr; }
};
template<typename T>Stack<T>::~Stack() { MakeEmpty(); }
template<typename T>void Stack<T>::MakeEmpty() {
	Node <T>*temp;
	while (top != nullptr) {
		temp = top;
		top = top->link;
		delete temp;
	}
}
template <typename T>void Stack<T>::Push(const T &data) {
		top = new Node<T>(data, top);
	}
template<typename T>T Stack<T>::Pop() {
		assert(!IsEmpty());
		Node <T>*temp = top;
		T data = temp->info;
		top = top->link;
		delete temp;
		return data;
	}
template<typename T>T Stack<T>::GetTop(){
	assert(!IsEmpty());
	return top->info;
	}