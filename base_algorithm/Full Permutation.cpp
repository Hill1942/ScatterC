void Swap(int& a, int& b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

int num = 0;

void f(int a[], int start, int end)
{
	if (start == end)
	{
		for (int j = 0; j <= end; j++)
		{
			cout << a[j] << " ";
		}
		cout << endl;
		num++;
	}
	else
	{
		for (int i = start; i <= end; i++)
		{
			Swap(a[i], a[start]);
			f(a, start + 1, end);		
			Swap(a[i], a[start]);
		}
	}
}
