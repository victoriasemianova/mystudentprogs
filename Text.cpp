#include <iostream>
#include <string>
#include <fstream>
#include <stack>
#include <assert.h>
using namespace std;


void main() {

	string word1, word2, word3;
	string value, current;

	ifstream fin;
	fin.open("input.txt");
	assert(fin.is_open());

	stack <string> St;

	fin >> word1 >> word2 >> word3;

	while (fin >> value) {
		if ((value == word1) ||
			(value == word1 + '.') ||
			(value == word1 + '!') ||
			(value == word1 + '?') ||
			(value == word1 + ',') ||
			(value == '"' + word1 + '"')) {

			int n = value.size();
			if ((value[n - 1] == ',') ||
				(value[n - 1] == '.') ||
				(value[n - 1] == '!') ||
				(value[n - 1] == '?')) {

				St.push(word2 + value[value.size() - 1]);
			}
			else
				if ((value[0] == '"') && (value[n - 1] == '"'))
					St.push('"' + word2 + '"');

				else
					St.push(word2);
		}
		else
			if ((value == word3) ||
				(value == word3 + ".") ||
				(value == word3 + "!") ||
				(value == word3 + "?") ||
				(value == word3 + ",")) {

				current = St.top();

				while ((St.empty() == false) && ((current[current.size() - 1] != '.'))) {

					current = St.top();
					St.pop();
				}

				fin >> value;
				while (value[value.size() - 1] != '.')
					fin >> value;
			}
			else
				St.push(value);
	}

	fin.close();

	stack <string> Reverse_St;

	while (St.empty() == false) {
		Reverse_St.push(St.top());
		St.pop();
	}

	ofstream fout;
	fout.open("output.txt");
	assert(fout.is_open());

	while (Reverse_St.empty() == false) {
		fout << Reverse_St.top() << ' ';
		Reverse_St.pop();
	}

	fout.close();

}