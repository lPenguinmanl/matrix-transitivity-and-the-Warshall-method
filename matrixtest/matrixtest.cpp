#include<iostream>
#include<fstream>
#include<math.h>
#include<algorithm>
using namespace std;
int Have_the_root(int num);
bool Is_Transitivity(int** arr, int size);
void The_Warshall_Method(int** arr, int size);
int main()
{
	setlocale(LC_ALL, "ukr");
	fstream Matrix;
	fstream matrix1;
	Matrix.open("MATRIX.txt", ios::in);
	int amounf_of_elements = 0, size, temp;
	if (Matrix.is_open())
	{
		while (!Matrix.eof())
		{
			Matrix>>temp;
			amounf_of_elements++;
		}
	}
	else
	{
		cout << "Помилка з файлом" << endl;
		return 0;
	}
	cout << "Перевiрка вхiдних даних" << endl;
	if (Have_the_root(amounf_of_elements) != 0)
	{
		cout << "Все добре" << endl;
		size = Have_the_root(amounf_of_elements);
	}
	else
	{
		cout << "Упс якась помилка з даними" << endl;
		return 0;
	}
	Matrix.close();
	matrix1.open("MATRIX.txt", ios::in);
	int** REAL_MATRIX = new int* [size];
	for (int i = 0; i < size; i++)
	
	{
		REAL_MATRIX[i] = new int[size];
		for (int j = 0; j < size; j++)
		{
			matrix1 >> REAL_MATRIX[i][j];
		}
	}
	if (Is_Transitivity(REAL_MATRIX, size))
	{
		cout << "Матриця транзитивна" << endl;
		
	}
	else
	{
		cout << "Матриця  не транзитивна" << endl;
		cout << "Транзитивне замикання методом Уоршелла" << endl;
		The_Warshall_Method(REAL_MATRIX, size);
	}
	for (int i = 0; i < size; i++)
	{
		delete REAL_MATRIX[i];
	}
	delete REAL_MATRIX;
	matrix1.close();
	return 0;
}
int Have_the_root(int num)
{
	for (int i = 1; i < 11; i++)
	{
		if (num == i * i)return i;
	}
	return 0;
}
bool Is_Transitivity(int** arr, int size)
{
	bool res;
	for (int k = 0; k < size; k++)
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				res = arr[i][j] >= min(arr[i][k], arr[k][j]);
				if (!res)
				{
					return res;
				}
			}
		}
	}
	return res;
}
void The_Warshall_Method(int** arr, int size)
{
	for (int k = 0; k < size; k++)
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				arr[i][j] = arr[i][j] || (arr[i][k] && arr[k][j]);
			}
		}
	}
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}