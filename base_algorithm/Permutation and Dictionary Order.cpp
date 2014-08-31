#include <iostream>

using namespace std;

int factorial(int n) 
{
	if (n <= 1) 
		return 1;
	else 
		return n * factorial(n - 1);
}

void _swap(int &a, int &b) 
{
	int temp = a;
	a = b;
	b = temp;
}

int getIndex(int *a, int n) 
{
	int index = 0; 
	index += (a[0] - 1) * factorial(n - 1);
	for (int i = 1; i < n - 1; i++) 
	{
		int temp = 0;
		for (int j = i + 1; j < n; j++ ) 
		{
			if (a[i] > a[j]) 
				temp++;
		}
		index += temp * factorial(n - i - 1);
	}
	return index;
}

int getNextPermutation(int *a, int n) 
{
	int temp;
	for (int i = n - 1; i > 0; i--) 
	{
		if (a[i] > a[i - 1]) 
		{
			temp = i - 1;
			break;
		}		
	}
	for (int i = n - 1; i > 0; i--) 
	{
		if (a[i] > a[temp]) 
		{
			_swap(a[i], a[temp]);
			break;
		}
	}
	int times = (n - temp - 1) / 2;
	for (int i = 1; i <= times; i++) 
	{
		_swap(a[i + temp], a[n - i]);
	}
	return 0;
}
int main() 
{
	int a[] = {4, 3, 2, 6, 5, 1, 7};

	cout << "Current permutation: " ;
	for (int i = 0; i < 7; i++) 
	{
		cout << a[i] << " " ;
	}
	cout << endl;

	cout << "The index based on zero is: " << getIndex(a, 7) << endl;

	getNextPermutation(a, 7);

	cout << "The next permutation is: ";
	for (int i = 0; i < 7; i++) 
	{
		cout << a[i] << " " ;
	}
	cout << endl;

	return 0;
}