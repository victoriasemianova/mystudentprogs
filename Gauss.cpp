#include<iostream>
#include<assert.h>
#include<stdio.h>
#include<fstream>
#include<stdlib.h>
using namespace std;




void swap(float* a, float* b) {
	float c = *a;
	*a = *b;
	*b = c;
}


//ты вводишь матрицу
void InitMatrix(int n, float** A) {
	float x;
	for (int j = 1; j <= n; j++) {
		for (int i = 1; i <= n + 1; i++) {
			cin >> x;
			A[j][i] = x;
		}
		cout << "\n";

	}
}


//экспоненциальная матрица (сама создается)
void InitMatrixExp(int n, float** A) {
	float x;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
				A[i][j] = exp(-abs(i - j));
		}
		cout << "\n";
	}
	
	A[1][n + 1] = 1;
	for (int i = 2; i <= n; i++) 
		A[i][n + 1] = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n + 1; j++)
			cout << A[i][j] << " ";
		cout << "\n";
	}

}


//работоспособность под вопросом
//проверка на ненулевой А[1][1]
void ZeroChecking(int n, float** A) {
	int i = 1;
	int j = 2;
	while (A[1][1] == 0) {
		while (j <= n) {
			for (i = 1; i <= n + 1; i++)
				swap(&(A[1][i]), &(A[j][i]));
			j++;
			cout << "j = " << j;
			i = 1;
		}
	}

	cout << "\n zero check \n";
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n + 1; j++)
			cout << A[i][j] << " ";
		cout << "\n";
	}

}

//приведение к верхнетреугольному виду
void Gauss1(int n, float** A) {
	float a;
	for (int k = 1; k <= n - 1; k++) { // k это номер шага   
		if (A[k][k] != 0) {

			a = A[k][k];
			for (int i = k; i <= n + 1; i++) 
				A[k][i] /= a;   	//делим все переменные строки k на A[k][k] 

			for (int i = k + 1; i <= n; i++) {
				for (int j = k + 1; j <= n + 1; j++) 
					A[i][j] -= A[i][k] * A[k][j];
				cout << "\n";
			}

			for (int j = k + 1; j <= n; j++)
				A[j][k] = 0;

			cout << "Reduction to the upper triangular form:\n\n";
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n + 1; j++)
					cout << A[i][j] << "     ";
				cout << "\n";
			}
			cout << "\n\n";
		}
	}
}



//вычисление иксов
void Gauss2(int n, float** A, float** B) {

	float* X = new float[n];

	X[n] = A[n][n + 1] / A[n][n];

	int j = n;
	for (int i = n - 1; i >= 1; i--) {
		X[i] = A[i][n + 1];
		while ((j >= 2) && (j > i)) {
			X[i] -= A[i][j] * X[j];
			j--;
		}
		j = n;
	}

	for (int i = 1; i <= n; i++)
		cout << "\n" << "x[" << i << "]=" << X[i] << "\n";


	float* C = new float[n];
	/*
	cout << " \n\n\nChecking: \n\n";
	for (int i = 1; i <= n; i++) {
		C[i] = 0;
		for (int k = 1; k <= n; k++)
			C[i] += B[i][k] * X[k];
		
		cout << C[i] << "\n";
	}
	cout << "\n";
	*/

	cout << " \n\n\nChecking: \n\n";
	for (int i = 1; i <= n; i++) {
		cout << B[i][n+1] << "\n";
	}
	cout << "\n";
}



void main() {
	

	/*
	int n;
	ifstream fin;
	fin.open("input.txt");
	assert(fin.is_open());
	fin >> n;

	float** A = new float*[n];
	for (int j = 1; j <= n; j++)
		A[j] = new float[n + 1];

	float x;
	for (int j = 1; j <= n; j++) {
		for (int i = 1; i <= n + 1; i++) {
			fin >> x;
			A[j][i] = x;
		}
		cout << "\n";
	}

	fin.close();

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n + 1; j++)
			cout << A[i][j] << " ";
		cout << "\n";
	}

	float** B = new float*[n];
	for (int j = 1; j <= n; j++)
		B[j] = new float[n + 1];

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n + 1; j++)
			B[i][j] = A[i][j];
	}

	

	//*/

	

	
	int n;
	//cout << "Matrix size: ";
	cin >> n;

	float** A = new float*[n];
	for (int j = 1; j <= n; j++)
		A[j] = new float[n + 1];

	InitMatrixExp(n, A);
	

	float** B = new float*[n];
	for (int j = 1; j <= n; j++)
		B[j] = new float[n + 1];

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n + 1; j++)
			B[i][j] = A[i][j];
	}


	cout << "\nCopy:\n";
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n + 1; j++)
			cout << B[i][j] << " ";
		cout << "\n";
	}
	//*/

	Gauss1(n, A);

	Gauss2(n, A, B);


}
