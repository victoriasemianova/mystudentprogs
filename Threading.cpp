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

	for (int i = 1; i <= threads_amount; i++) //����� ����� ����� ������������ � �������� potok
		thread potok(reading, fin); //�������� � ������ ������ ������, reading ��� ������� � ������� ���������� ���� ������� ������ ������
	                               //����� ������� �� ������� ���������

}