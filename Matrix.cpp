#include <iostream>
#include <fstream>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
using namespace std; 


class Matrix {
	int** M;
	int n;

	//allocate memory
	void memory() {
		M = new int*[n];
		assert(M);
		for (int j = 0; j < n; j++) {
			M[j] = new int[n];
			assert(M[j]);
		}
	}

	void clean(){
		for (int i = 0; i < n; i++)
		delete[] M[i];
	delete[] M;
	}

public:

	friend ifstream& operator >> (ifstream& s, Matrix& that);

	//random matrix constructor
	Matrix(int n) {
		srand(time(NULL));
		this->n = n;
		memory();
		for (int j = 0; j < n; j++)
			for (int i = 0; i < n; i++)
				M[j][i] = rand() % 10; 
	}


	//diag matrix constructor
	Matrix(int n, int k) {
		this->n = n;
		memory();
		for (int j = 0; j < n; j++)
			for (int i = 0; i < n; i++) {
				if (i == j) M[j][j] = k;
				else M[j][i] = 0;
			}
	}


	//copy constructor
	Matrix(const Matrix& that) { 
		this->n = that.getn();
		init(that);
	}

	Matrix operator+(const Matrix& that) {
		assert(this->n == that.n);
		Matrix result(n);
			for (int j = 0; j < n; j++)
				for (int i = 0; i < n; i++) {
					result.M[j][i] = M[j][i] + that.M[j][i];
				}
		
		return result;
	}

	Matrix operator*(const Matrix& that) const {
		if (this->n != that.n)
			assert(0);
		
		Matrix result(n, 0);
		for (int j = 0; j < n; j++)
				for (int i = 0; i < n; i++)
					for (int k = 0; k < n; k++)
						result.M[j][i] += this->M[j][k] * that.M[k][i];
		return result;
	}

	void init(const Matrix& that) {
		this->memory();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				this->M[i][j] = that.M[i][j];
			}
		}
	}

	Matrix& operator= (const Matrix& that)  {
		if (this != &that) {
			clean();
			this->n = that.getn();
			init(that);
		}
		return *this;
	}

	void transp() {
		int m;
		for (int j = 0; j < this->n; j++)
			for (int i = j + 1; i < n; i++) {
				m = M[j][i];
				M[j][i] = M[i][j];
				M[i][j] = m;
			}
	}

	void fprint(ofstream& fout) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				fout << M[i][j] << " ";
			}
			fout << "\n";
		}
	}
	void print() {
		for (int j = 0; j < n; j++) {
			for (int i = 0; i < n; i++)
				cout << M[j][i] << " ";
			cout << "\n";
		}
	}

	~Matrix() {		
		clean();
	}

	int getn() const {
		return n;
	}
};

ifstream& operator >> (ifstream& s, Matrix& that) {
	int n = that.getn();
	for (int j = 0; j < n; j++) {
		for (int i = 0; i < n; i++) {
			s >> that.M[j][i];
		}
	}
	return s;
}

int main() {

	ifstream fin; //переменная типа ifstream для чтения из файла
	fin.open("input.txt");
	assert(fin.is_open());
	int n, k;
	fin >> n;
	fin >> k;
	Matrix A(n);
	Matrix B(n);
	Matrix C(n);
	Matrix D(n);
	fin >> A >> B >> C >> D;
	Matrix K(n, k);
	fin.close();

	
	C.transp();

	D.transp();
	Matrix R(n,0);
	R = (A + (B*C) + K)*D;
	
	ofstream fout; 
	fout.open("output.txt");
	R.fprint(fout);
	fout.close();

	return 0;
}