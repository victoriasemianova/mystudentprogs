#include<iostream>
#include<assert.h>
#include<stdio.h>
#include<stdlib.h>
using std::cout;
using std::cin;

class Stack {
	int *buffer;
	int capacity;
	int size;

public:

	Stack(int cap){
		assert(cap);
		buffer = (int*)malloc(cap*sizeof(int));
		assert(buffer);
		capacity = cap;
		size = 0;
	}


	void push(int x){ //add x to the stack
		if (size == capacity)
			capacity *= 2;
			buffer = (int*)realloc(buffer, capacity*sizeof(int));
		buffer[size++] = x;

	}
	int pop(){ //убрать
		assert(size); 
		return buffer[--size];
	}

	int peek(){ //посмотеть
		assert(size);
		return buffer[size-1];
	}

	int getSize (){
		return size;
	}
	~Stack() {
		free(buffer);
	}
};

void main() {
	Stack st(8);
	st.push(41);
	cout << "sise: " << st.getSize() << "\n";
	cout << "el was: " << st.pop() << "\n";
	cout << "sise: " << st.getSize() << "\n";

	// fail // cout << "el was: " << st.pop() << "\n";

	st.push(41);
	st.push(42);
	st.push(43);
	cout << "sise: " << st.getSize() << "\n";
	cout << "el: " << st.peek() << "\n";
	cout << "sise: " << st.getSize() << "\n";
	cout << "el was: " << st.pop() << "\n";
	cout << "sise: " << st.getSize() << "\n";
	for (int i = 43; i <= 49; i++)
		st.push(i);
	cout << "el: " << st.peek() << "\n";
	cout << "sise: " << st.getSize() << "\n";
}