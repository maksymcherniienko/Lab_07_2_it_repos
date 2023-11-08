#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High);
void Print(int** a, const int rowCount, const int colCount);
void FindMax(int** a, const int n, int& max);

int main()
{
	srand((unsigned)time(NULL));
	int Low = -42;
	int High = 51;
	int max;
	int rowCount = 4;
	int colCount = 4;
	int** a = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		a[i] = new int[colCount];
	Create(a, rowCount, colCount, Low, High);
	Print(a, rowCount, colCount);
	FindMax(a, rowCount, max);
	cout << endl << "max = " << max << endl;
	delete[] a;
	return 0;
}

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High)
{
	for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < colCount; j++)
			a[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** a, const int rowCount, const int colCount)
{
	cout << endl;
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
			cout << setw(5) << a[i][j];
		cout << endl << endl;
	}
	cout << endl;
}

void FindMax(int** a, const int n, int& max)
{
	max = a[0][0]; // перший елемент головної діагоналі

	for (int i = 0; i < n; i++)
	{
		if (a[i][i] > max)
		{
			max = a[i][i]; // більший елемент
		}
	}
}

