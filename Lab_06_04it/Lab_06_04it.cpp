#include <iostream>
#include <time.h>

using namespace std;

void Generate(int* a, const int n, int low, int high)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = low + rand() % (high - low + 1);
	}
}

void print(int* a, const int n)
{
	cout << "a[] = { ";
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << "}" << endl;
}

int Multiple(int* a, const int n)
{
	int p = 1;
		for (int i = 0; i < n; i++)
			if (i % 2 == 0 && i != 0)
				p *= a[i];

		return p;
}

int findfirst(int* a, const int n)
{
	for (int i = 0; i < n; i++)
		if (a[i] == 0)
			return i;

	return -1;
}

int findlast(int* a, const int n)
{
	for (int i = n - 1; i >= 0; i--)
		if (a[i] == 0)
			return i;

	return -1;
}

int Sum(int* a, const int n)
{
	int sum = 0;
	int first = findfirst(a, n);
	int last = findlast(a, n);

	for (int i = first; i < last; i++)
	{
		sum += a[i];
		
	}

	return sum;
}

void Sort(int* a, int n)
{
	int j = 0;
	for (int i = 0; i < n; i++)
		if (a[i] >= 0)
		{
			if (i != j)
			{
                int tmp = a[i];
			    a[i] = a[j];
			    a[j] = tmp;
			}
			j++;
		}
}
int main()
{
	srand((unsigned)time(NULL));
	int n;
	cout << "Insert n:" << endl;
	cout << "n = "; cin >> n;

	const int high = 10;
	const int low = -10;
	int* a = new int[n];

	Generate(a, n, low, high);
	print(a, n);
	cout << "Multiplying matching numbers: " << Multiple(a, n) << endl;

	if (findfirst(a, n) == -1 || findlast(a, n) == -1)
		cout << "No zeroes in the array " << endl;
	else
		cout << "Sum of the matching numbers: " << Sum(a, n) << endl;
	    
	Sort(a, n);
	cout << "Sortified array: " << endl;
	print(a, n);

	delete[] a;

	system("pause");
	return 0;

}