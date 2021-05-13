#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	int n = 5;
	int i;
	int j;
	int k;
	double sum = 0;

	double A[5][5];
	double L[5][5];
	double U[5][5];
	double c[5][5];

	//задаем матрицу A[][] ...

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			A[i][j] = exp(-abs(i - j));

			L[i][j] = 0;
			U[i][j] = 0;

			if (i == j)
				U[i][j] = 1;
		}
	}


	cout << "Matrix A\n";
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			//Вывод значения элемента на экран:
			cout << A[i][j] << " ";
		}
		cout << endl;
	}


	//==============================================

	//находим первый столбец L[][] и первую строку U[][]

	for (int i = 0; i < n; i++)
	{
		L[i][0] = A[i][0];
		U[0][i] = A[0][i] / L[0][0];
	}

	//дальше вычисляем L[][], U[][] по формуле

	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < n; j++)
		{
			if (i >= j) //нижний треугольник
			{
				sum = 0;
				for (int k = 0; k < j; k++)
					sum += L[i][k] * U[k][j];

				L[i][j] = A[i][j] - sum;
			}
			else // верхний
			{
				sum = 0;
				for (int k = 0; k < i; k++)
					sum += L[i][k] * U[k][j];

				U[i][j] = (A[i][j] - sum) / L[i][i];
			}
		}
	}

	//====================================================
	cout << "\n\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << "  " << L[i][j] << "   ";
		cout << "\n\n";
	}

	cout << "\n\n";

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << "  " << U[i][j] << "   ";
		cout << "\n\n";
	}

	//Вычисление произведения матриц:
	cout << "Matrix A=LU:\n";
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			c[i][j] = 0;
			for (k = 0; k < n; k++)
				c[i][j] += L[i][k] * U[k][j];
			//Вывод значения элемента на экран:
			cout << c[i][j] << " ";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}