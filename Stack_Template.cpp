#include<iostream>
#include<assert.h>
#include<stdio.h>
#include<stdlib.h>
#include<fstream>
#include<string>
using namespace std;
std::string;

template <typename T>

class Stack {
	T * buffer;
	int capacity;
	int size;

public:

	Stack(int cap) {
		buffer = new T[cap];
		capacity = cap;
		size = 0;
	}

	int getSize() {
		return size;
	}

	void push(T value) {

		if (size == capacity) {
			capacity *= 2;
			T * buf_copy = new T[capacity];

			for (int i = 0; i < size; i++)
				buf_copy[i] = this->buffer[i];

			this->buffer = buf_copy;
		}

		buffer[size++] = value;
		
	}

	//zachem popu delat' tip T ?? c voidom vse gorazdo priyatnee
	void pop() { //убрать
		if (IsEmpty() == false) {//тут точно все правильно!!
			--size;
		}
	}

	/*
	T pop() { //убрать
		if (IsEmpty() == false) {//тут точно все правильно!!
			return buffer[--size];
		}
		else return buffer[0];
	}
	

	T summator() {
		T sum = buffer[0];
		for (int i = 1; i < size; i++) {
			sum += buffer[i];
		}
		return sum;
	}
	*/
	T summator() {
		T sum = buffer[size-1];
		for (int i = size - 2; i >= 0; i--) {
			sum += buffer[i];
		}
		return sum;
	}

	void FuncForSummator(ofstream& fout) {
		
		int size = getSize();
		fout << size << " ";
		
		if (size != 0) {
			fout << summator();
		}
		
	}

	void formation(int n, ifstream& fin) {

		string str;
		for (int i = 1; i <= n; i++) {

			fin >> str;

			if (str == "POP") {
				pop();
			}
			else if (str == "PUSH") {
				T value;
				fin >> value;
				push(value);

			}
		}


		ofstream fout;
		fout.open("output.txt");
		assert(fout.is_open());

		FuncForSummator(fout);

		fout.close();

	}

	bool IsEmpty() {
		if (getSize() == 0) {
			
			return true;
		}
		else return false;
	}
};



void main() {

	ifstream fin;
	fin.open("input.txt");
	assert(fin.is_open());
	char c;
	int n;
	fin >> c >> n;

	if (c == 'I') {

		Stack<int> St(1);
		St.formation(n, fin);
	}

	else if (c == 'D') {
		Stack<double> St(1);
		St.formation(n, fin);
	}

	else if (c == 'S') {
		Stack<string> St(1);
		St.formation(n, fin);
	}
	fin.close();
}