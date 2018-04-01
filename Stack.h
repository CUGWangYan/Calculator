#pragma once
#include <cassert>
#include <iostream>
using namespace std;
template<typename T>class Stack {
	int top;
	T *elements;
	int maxSize;
public:
	Stack(int maxs = 20) {
		maxSize = maxs;
		top = -1;
		elements = new T[maxSize];
		assert(elements != 0);
	};
	~Stack() {
		delete[]elements;
	}
	void Push(const T&data) {
		assert(!IsFull());
		elements[++top] = data;
	};
	T Pop() {
		assert(!IsEmpty());
		return elements[top--];
	};
	T GetElem(int i) {
		assert(i <= top&&i >= 0);
		return elements[i];
	};
	void MakeEmpty() { top = -1; }
	bool IsEmpty()const { return top = -1; }
	bool IsFull()const { return top == maxSize - 1; }
	void PrintStack() {
		for (int i = 0; i <= top; i++) cout << elements[i] << '\t';
		cout << endl;
	};

};