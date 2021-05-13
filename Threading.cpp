#include <iostream>
#include <string>
#include <fstream>
#include <stack>
#include <assert.h>
#include <thread>
using namespace std;

void reading(ifstream fin) {
	string value;
	while (fin >> value) {

	}
}

void main() {

	ifstream fin;
	fin.open("input.txt");
	assert(fin.is_open());

	int threads_amount;
	string check_word;
	fin >> threads_amount >> check_word;

	for (int i = 1; i <= threads_amount; i++) //новый поток будет ассоциирован с объектом potok
		thread potok(reading, fin); //создание и запуск нового потока, reading это функция с которой начинается стек вызовов нового потока
	                               //через запятую ее входные параметры

}