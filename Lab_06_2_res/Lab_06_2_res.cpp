#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int* a, const int size, const int Low, const int High, int i)
{
	a[i] = Low + rand() % (High - Low + 1);
	if (i < size - 1)
		Create(a, size, Low, High, i + 1);
}

void Print(int* a, const int size, int i)
{
	cout << setw(4) << a[i];
	if (i < size - 1)
		Print(a, size, i + 1);
	else
		cout << endl;
}

int Max(int* a, const int size, int max, int imax, int i)
{
	if (a[i] > max)
	{
		max = a[i];
		imax = i;
	}
	if (i < size - 1)
		return Max(a, size, max, imax, i + 1);
	else
		return imax;
}


int Min(int* a, const int size, int min, int imin, int i)
{
	if (a[i] < min)
	{
		min = a[i];
		imin = i;
	}
	if (i < size - 1)
		return Min(a, size, min, imin, i + 1);
	else
		return imin;
}

int Sum(int* a, const int size, int S, int i, int max, int min, int imax, int imin)
{
	S = Max(a, size, max, imax, i) + Min(a, size, min, imin, i);
		return S;
}

int main()
{
	srand((unsigned)time(NULL));

	const int n = 10;
	int a[n];

	int Low = -12;
	int High = 30;

	int S = 0;
	int max = 0;
	int min = 0;
	int imax = -1;
	int imin = -1;

 	Create(a, n, Low, High, 0);
	cout << "Original masive" << endl;
	Print(a, n, 0);
	cout << endl;

	cout << "Calculating imax and imin" << endl;
	cout << "imax = " << Max(a, n, max, imax, 0) << endl;
	cout << "imin = " << Min(a, n, min, imin, 0) << endl;
	cout << endl;
	
	cout << "Calculacting sum" << endl;
	cout << "S = " << Sum(a, n, 0, 0, max, min, imax, imin) << endl;
	cout << endl;
	
	system("pause");
	return 0;
}