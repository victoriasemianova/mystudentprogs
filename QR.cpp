#include<iostream>
#include <fstream>
#include <math.h>
#include <vector>
#include <iomanip>

using namespace std;

void PrintMatrix(vector < vector < double» const & matrix)
{
	int i, j;
	for (i = 0; i < matrix.size(); i++) {
		for (j = 0; j < matrix[i].size(); j++) {
			cout « matrix[i][j] « " ";
		}
		cout « "\n";
	}
	cout « "\n";
}

vector < vector < double» Mul(vector < vector < double» const & t, vector < vector < double» const & that) {
	double sum;
	int n = t.size();

	vector < vector < double» tmp(n, vector<double>(n, 0));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			sum = 0;

			for (int k = 0; k < n; k++) {
				sum += t[i][k] * that[k][j];
			}

			tmp[i][j] = sum;
		}
	}

	return tmp;
}

int main()
{
	int a;
	setlocale(LC_ALL, "rus");

	cout « "Ââåäèòå ÷èñëî çíàêîâ ïîñëå çàïÿòîé:\n";
	cin » a;
	cout « fixed « setprecision(a);


	int n, m, count = 0;
	cout « endl « "Ââåäèòå ðàçìåðíîñòü ìàòðèöû A:\n";
	cin » n;
	m = n + 1;

	vector < vector < double» matrixAb(n, vector<double>(m));
	for (int i = 0; i < matrixAb.size(); i++) {
		for (int j = 0; j < matrixAb[i].size(); j++) {
			matrixAb[i][j] = 1 / exp(abs(i - j));
		}
	}

	for (int i = 0; i < n; i++) {
		if (i == n / 2)
			matrixAb[i][n] = 1;
		else
			matrixAb[i][n] = 0;
	}

	cout « endl « "Ìàòðèöà A:\n";
	PrintMatrix(matrixAb);

	int maxR;
	double long maxValue1 = 0;
	double long maxValue2 = 0;

	double long Help = 0;

	vector < vector < double» Q(n, vector<double>(n, 0));
	vector < vector < double» R(n, vector<double>(n));

	for (int i = 0; i < n; i++)
		Q[i][i] = 1;

	for (int k = 0; k < n; k++) {
		// ìåòîä âðàùåíèÿ
		for (int i = k + 1; i < n; i++)
		{
			double cos = matrixAb[k][k] / sqrt(matrixAb[k][k] * matrixAb[k][k] + matrixAb[i][k] * matrixAb[i][k]); //sqr(cos) + sqr(sin) = 1;
			double sin = matrixAb[i][k] / sqrt(matrixAb[k][k] * matrixAb[k][k] + matrixAb[i][k] * matrixAb[i][k]); //
			for (int j = k; j <= n; j++)
			{
				double prm = cos * matrixAb[k][j] + sin * matrixAb[i][j];
				matrixAb[i][j] = -sin * matrixAb[k][j] + cos * matrixAb[i][j];
				matrixAb[k][j] = prm;
			}

			vector < vector < double» Qtmp(n, vector<double>(n, 0));

			for (int j = 0; j < n; j++)
				Qtmp[j][j] = 1;

			Qtmp[k][k] = cos;
			Qtmp[i][i] = cos;

			Qtmp[k][i] = -sin;
			Qtmp[i][k] = sin;

			Q = Mul(Q, Qtmp);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			R[i][j] = matrixAb[i][j];
		}
	}

	vector<long double> X(n);
	X[n - 1] = matrixAb[n - 1][n] / matrixAb[n - 1][n - 1];
	matrixAb[n - 1][n] = X[n - 1];
	//Îáðàòíûé õîä:
	for (int i = n - 2; i >= 0; i--)
	{
		for (int j = i + 1; j < n; j++) //íàõîäèì b - (x_i * k_i)
		{
			X[i] = matrixAb[i][n] - X[j] * matrixAb[i][j];
			matrixAb[i][n] = X[i];
		}
		X[i] /= matrixAb[i][i];
	}

	cout « "Âåêòîð x:\n";
	for (int i = 0; i < n; i++) {
		cout « "x" « i + 1 « "=" « X[i] « endl;
	}

	/*for (int i = 0; i < n; i++) {
	if (R[i][i] < 0)
	for (int j = i; j < n; j++)
	R[i][j] *= -1;
	}*/

	cout « endl « "R - âåðõíÿÿ òðåóãîëüíàÿ ìàòðèöà:" « endl;
	PrintMatrix(R);
	cout « "Q - îðòîãîíàëüíàÿ ìàòðèöà" « endl;
	PrintMatrix(Q);

	cout « "Ïðîâåðêà Q*R = A?:" « endl;
	PrintMatrix(Mul(Q, R));

	system("pause");

	return 0;
}
Close
