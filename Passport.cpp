#include<iostream>
#include<assert.h>
#include<stdio.h>
#include<stdlib.h>
using std::cout;
using std::cin;

class Passport {
	char* name;
	int number;
	

public:
	Passport(char* name, int number) {
		this->name = name;
		this->number = number;
	}

	char* GetName() {
		return this->name;
	}
		
	int GetNumber() {
		return this->number;
	}
};

class Account {
	int money;
};

class Client {
	Passport pasport;
	Account acc;

public:
	Client(char* name, int number, int money)
		:passport(name, number),
		account(new Account(money))
};

void main() {

}