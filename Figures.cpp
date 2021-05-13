#include <iostream>
#include <fstream>
#include <string>
#include <assert.h>
using namespace std;


class Figure {

public:
	virtual double area() = 0;  //� ������ ������ ���� �������, �� ���� �� ����� ������, �� ����� ��������� �������

};

class Square : public Figure {
	double s; //�������

public:
	Square (double x)  {
		this->s = x;
	}
	double area() {
		return s * s;
	}
};


class Triangle : public Figure{
	double t; //�������

public:
	Triangle(double x)  {
		this->t = x;
	};
	double area() {
		return (t * t * sqrt(3)) / 4;
	}
};


class Circle : public Figure {
	double r; //������

public:
	Circle(double x) {
		this->r = x;
	}
	double area() {
		return r * r * 3.14159265358979;
	}
};

int main() {
	int n = 0;
	double sum = 0;
	double x;
	char type;

	ifstream fin;
	fin.open ("input.txt");
	assert(fin.is_open());
	fin >> n;

	Figure** Figures = new Figure*[n];
	

	for (int i = 0; i < n; i++) {
		fin >> type;
		fin >> x;

		if (type == 'S') {
			Figures[i] = new Square(x); //������� ��������
			
		}
		else if (type == 'T') {
			Figures[i] = new Triangle(x); //������� ������������
			
		}
		else if (type == 'C') {
			Figures[i] = new Circle(x); //������ �����
			
		}
		sum += Figures[i]->area();
	}

	

	ofstream fout;
	fout.open ("output.txt");
	assert(fout.is_open());
	fout << fixed;
	fout.precision(2);
	fout << sum ;

	fin.close();
	fout.close();

	for (int i = 0; i < n; i++)
		delete[] Figures[i];

	delete Figures;

	return 0;
}