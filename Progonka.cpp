#include<iostream>
#include<assert.h>
#include<stdio.h>
#include<fstream>
#include<stdlib.h>
using namespace std;



void Progonka(int n, float** A, float* B, float** Copy) {
	// это прогоночные коэффициенты
	float* u = new float[n]; // слева от =
	float* y = new float[n]; // справа от =

	u[1] = -A[1][2] / A[1][1];
	y[1] = B[1] / A[1][1];

	for (int i = 2; i <= n; i++) {
		float k = A[i][i] + A[i][i - 1] * u[i - 1];
		u[i] = -A[i][i + 1] / k;
		y[i] = (B[i] - A[i][i - 1] * y[i - 1]) / k;
	}


	// нахождение иксов
	float* X = new float[n];
	X[n] = (B[n] - A[n][n - 1] * y[n - 1]) / (A[n][n] + A[n][n - 1] * u[n - 1]);

	for (int i = n - 1; i >= 1; i--)
		X[i] = u[i] * X[i + 1] + y[i];

	for (int i = 1; i <= n; i++)
		cout << "\n" << "x[" << i << "]=" << X[i] << "\n";

	float* Res = new float[n];
	

	cout << " \n\n\nChecking: \n\n";
	for (int i = 1; i <= n; i++) {
		Res[i] = 0;
		for (int k = 1; k <= n; k++)
			Res[i] += Copy[i][k] * X[k];

		cout << Res[i] << "\n";
	}
	cout << "\n";
}



void main() {

	int n;
	ifstream fin;
	fin.open("input.txt");
	assert(fin.is_open());
	fin >> n;

	float** A = new float*[n];
	for (int j = 1; j <= n; j++)
		A[j] = new float[n + 1];//3-ехдиагональная матрица 

	float* B = new float[n]; // столбец чисел
	float x;
	for (int j = 1; j <= n; j++) {
		for (int i = 1; i <= n + 1; i++) {
			fin >> x;
			if (i != n + 1)
				A[j][i] = x;
			else B[j] = x;
		}
		cout << "\n";
	}

	fin.close();

	float** Copy = new float*[n];
	for (int j = 1; j <= n; j++)
		Copy[j] = new float[n + 1];

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n + 1; j++)
			Copy[i][j] = A[i][j];
	}

	Progonka(n, A, B, Copy);

}