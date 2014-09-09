template<typename T>
void Bubble_Sort(T a[], int n) 
{
	for (int i = 0; i < n - 1; i++) 
	{
		for (int j = 1; j < n - i; j++) 
		{
			if (a[j] < a[j - 1]) 
			{
				T temp = a[j];
				a[j] = a[j - 1];
				a[j - 1] = temp;
			}
		}
	}
}

template<typename T>
void Select_Sort(T a[], int n) 
{
	for (int i = 0; i < n; i++) 
	{
		int min = a[i];
		for (int j = i + 1; j < n; j++) 
		{
			if (a[j] < min) 
			{
				T temp = min;
				min = a[j];
				a[j] = temp;
			}
		}
		a[i] = min;
	}
}

template<typename T>
void Insert_Sort(T a[], int n)
{
	for (int i = 1; i < n; i++) 
	{
		int j = i;
		while (a[j - 1] > a[j] && j > 0) 
		{
			T temp = a[j - 1];
			a[j - 1] = a[j];
			a[j] = temp;
			j--;
		}
	}
}

template<typename T>
void Quick_Sort(T a[], int start, int end) 
{
	if (start < end) 
	{
		int guard = a[start];
		int guard_pos = start;
		for (int i = start + 1; i <= end; i++)
		{			
			if (a[i] < guard) 
			{
				guard_pos++;
				T temp = a[guard_pos];
				a[guard_pos] = a[i];
				a[i] = temp;
			}
		}
		a[start] = a[guard_pos];
		a[guard_pos] = guard;
		Quick_Sort(a, start, guard_pos - 1);
		Quick_Sort(a, guard_pos + 1, end);
	}
}


template<typename T>
void Merge_Sort(T a[], T na[], int start, int end) 
{
	if (start >= end) 
	{
		return;
	}
	int mid = (start + end) / 2;
	Merge_Sort(a, na, start, mid);
	Merge_Sort(a, na, mid + 1, end);

	for (int i = start; i <= end; i++) 
	{
		na[i] = a[i];
	}

	int s1 = start;
	int s2 = mid + 1;
	int t = start;
	while (s1 <= mid && s2 <= end)
	{
		if (na[s1] <= na[s2])
		{
			a[t] = na[s1];
			t++;
			s1++;
		} 
		else 
		{
			a[t] = na[s2];
			t++;
			s2++;
		}
	}
	while (s1 <= mid) 
	{
		a[t] = na[s1];
		t++;
		s1++;
	}
	while (s2 <= end) 
	{
		a[t] = na[s2];
		t++;
		s2++;
	}
}