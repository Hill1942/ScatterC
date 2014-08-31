template<typename T>
int b_search(T* a, int n, const T& x)
{
	int left = 0;
	int right = n - 1;
	while (left <= right)
	{
		int center = (left + right) / 2;
		if (x == a[center])
			return center;
		if (x > a[center])
			left = center + 1;
		else
			right = center - 1;
	}
	return -1;
}

template<typename T>
int b_search_recursion(T* a, int n, int start, int end, const T& x)
{
	if (start > end)
	{
		return -1;
	}

	int center = (start + end) / 2;
	if (x == a[center])
	{
		return center;
	}
	else if (x < a[center])
	{
		return b_search(a, n, start, center - 1, x);
	}
	else 
	{
		return b_search(a, n, center + 1, end, x);
	}
}