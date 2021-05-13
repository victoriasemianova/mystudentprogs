#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <math.h>
#include <assert.h>
#include <malloc.h>
#include <iomanip>

using namespace std;

double const eps = 0.00000001;

class Matrix {
public:
	double ** field;
	int n;

	void memorySet() {
		field = new double*[n];

		for (int i = 0; i < n; i++)
			field[i] = new double[n];
	}

	void memoryClean() {
		for (int i = 0; i < n; i++)
			delete[] field[i];

		delete[] field;
	}

public:

	Matrix(int n) {
		this->n = n;
		memorySet();

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				field[i][j] = exp(-abs(i - j));
			}
		}
	}

	Matrix(int n, int k) {
		this->n = n;
		memorySet();

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i == j)
					field[i][j] = k;
				else
					field[i][j] = 0;
			}
		}
	}

	Matrix(Matrix const & that) {
		this->n = that.n;
		memorySet();

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				field[i][j] = that.field[i][j];
			}
		}
	}

	Matrix operator+ (Matrix const & that) const {
		assert(!(this->n - that.n)); // разный размер матриц 

		Matrix tmp(*this);

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				tmp.field[i][j] += that.field[i][j];
			}
		}

		return tmp;
	}

	Matrix operator* (Matrix const & that) const {
		assert(!(this->n - that.n)); // разный размер матриц 

		Matrix tmp(this->n);
		double sum;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				sum = 0;

				for (int k = 0; k < n; k++) {
					sum += field[i][k] * that.field[k][j];
				}

				tmp.field[i][j] = sum;
			}
		}

		return tmp;
	}

	Matrix & operator= (Matrix const & that) {
		if (this == &that)
			return *this;

		this->memoryClean();

		this->n = that.n;
		this->memorySet();

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				field[i][j] = that.field[i][j];
			}
		}

		return *this;
	}

	Matrix & transpose() {
		int tmp;

		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				tmp = field[i][j];
				field[i][j] = field[j][i];
				field[j][i] = tmp;
			}
		}

		return *this;
	}

	Matrix & lu(Matrix & l, Matrix & u) {
		for (int i = 0; i < n; i++) {

			for (int j = 0; j < n; j++) {
				if (j < i)
					l.field[j][i] = 0;
				else {
					l.field[j][i] = this->field[j][i];
					for (int k = 0; k < i; k++) {
						l.field[j][i] = l.field[j][i] - l.field[j][k] * u.field[k][i];
					}
				}
			}

			for (int j = 0; j < n; j++) {
				if (j < i)
					u.field[i][j] = 0;
				else if (j == i)
					u.field[i][j] = 1;
				else {
					u.field[i][j] = this->field[i][j] / l.field[i][i];
					for (int k = 0; k < i; k++) {
						u.field[i][j] = u.field[i][j] - ((l.field[i][k] * u.field[k][j]) / l.field[i][i]);
					}
				}
			}
		}

		return *this;
	}

	Matrix Find_reverse_matrix() {
		int i, j, k;

		Matrix copy(*this);
		Matrix rev(n, 1);
		for (i = 0; i < n; i++)
			rev.field[i][i] = 1;

		cout << endl;

		double temp;
		for (i = 0; i < n; i++) {
			temp = copy.field[i][i];
			for (j = 0; j < n; j++) {
				copy.field[i][j] /= temp;
				rev.field[i][j] /= temp;
			}

			for (k = 0; k < n; k++) {
				if (k == i)
					continue;

				temp = copy.field[k][i];
				for (j = 0; j < n; j++) {
					copy.field[k][j] -= copy.field[i][j] * temp;
					rev.field[k][j] -= rev.field[i][j] * temp;
				}
			}
		}

		return rev;
	}

	void print() {
		double print = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (abs(field[i][j] - print) < eps)
					cout << print << " ";
				else
					cout << field[i][j] << " ";
			}

			cout << endl;
		}
	}

	void printf(FILE * output) {
		fprintf(output, "\n");
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				fprintf(output, "%d ", field[i][j]);
			}
			fprintf(output, "\n");
		}
	}

	void readf(FILE * input) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				fscanf(input, "%d", &field[i][j]);
			}
		}
	}

	void read() {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> field[i][j];
			}
		}
	}

	~Matrix() {
		memoryClean();
	}
};

int main() {
	setlocale(LC_ALL, "Russian");
	cout << fixed << setprecision(3);

	int n;
	cin >> n;

	Matrix Q(n);
	Matrix Q_rev(n);
	Q_rev = Q.Find_reverse_matrix();
	Q.print();
	Q_rev.print();

	system("pause");
}