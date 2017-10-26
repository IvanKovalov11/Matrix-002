#include "stdafx.h"
#include <sstream>
#include <iostream>
#include <limits>

using namespace std;

bool create(int &m, int &n)
{
	string razmer;
	char op; int*t = new int;
	getline(cin, razmer);
	istringstream stream(razmer);
	stream >> *t;
	if (stream >> op && op == ',')
	{
		m = *t;
		delete t;
		if (!(stream >> n))
		{
			cout << "Wrong input";
			return false;
		}
		else return true;
	}
	else
	{
		cout << "Wrong input";
		return false;
	}
}

bool read(int **matrix, int str, int col)
{
	int k = 0;
	for (int i = 0; i < str; i++)
	{
		string row;
		getline(cin, row);
		istringstream stream(row);
		for (int j = 0; j < col; j++)
		{
			if (stream >> matrix[i][j]) { k++; }
		}
	}
	if (k == str*col) return true;
	else return false;
}

void print(int **matrix, int str, int col)
{
	for (int i = 0; i < str; i++)
	{
		cout << endl;
		for (int j = 0; j < col; j++)
		{
			cout << matrix[i][j] << " ";
		}
	}
}

void add(int **matrix1, int **matrix2, int str, int col)
{
	for (int i = 0; i < str; i++)
	{
		cout << endl;
		for (int j = 0; j < col; j++)
		{
			cout << matrix1[i][j] + matrix2[i][j] << " ";
		}
	}
}

void sub(int **matrix1, int **matrix2, int str, int col)
{
	for (int i = 0; i < str; i++)
	{
		cout << endl;
		for (int j = 0; j < col; j++)
		{
			cout << matrix1[i][j] - matrix2[i][j] << " ";
		}
	}
}


int main()
{
	int str1, col1;
	int str2, col2;
	static int **matrix1;
	static bool mat1 = false, mat2 = false;
	static int **matrix2;
	static char op;
	if (create(str1, col1))
	{
		matrix1 = new int*[str1];
			for (int i = 0; i < str1; i++)
			{
				matrix1[i] = new int[col1];
			}
			if (read(matrix1, str1, col1))
			{
				mat1 = true;
				cin >> op;
				cin.get();
			}
			else
			{
				cout << "Wrong input";
			}
		if (op == '+' || op == '-' || op == '*')
		{
			if (create(str2, col2))
			{
				matrix2 = new int*[str2];
					for (int i = 0; i < str2; i++)
					{
						matrix2[i] = new int[col2];
					}
					if (read(matrix2, str2, col2))
					{
						mat2 = true;
					}
					else
					{
						cout << "Wrong input";
						return 0;
					}
			}
			switch (op)
			{
			case '+':
				if (str1 == str2 && col1 == col2)
				{
					cout << "Result is:" << endl;
					add(matrix1, matrix2, str1, col1);
				}
				else
				{
					cout << "ERROR";
					break;
				}
			case '-':
				if (str1 == str2 && col1 == col2)
				{
					cout << "Result is:" << endl;
					sub(matrix1, matrix2, str1, col1);
				}
				else
				{
					cout << "ERROR";
					break;
				}
			}
		}
		else cout << "Wrong input";
		return 0;
	}
}
