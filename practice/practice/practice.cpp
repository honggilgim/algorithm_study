#include<iostream>
using namespace std;
int arr[1100000] = { 0 };

void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

void qsort(int i, int j)
{
	if (i >= j)
		return;
	i++;
	int pivot = arr[i];
	int first = i;
	int last = j;
	while (j >= i)
	{
		while (arr[i] < pivot) i++;
		while (arr[j] > pivot) j--;
		swap(arr[i], arr[j]);
	}
	if (pivot > arr[i])
		swap(arr[first], arr[i]);
	if (pivot < arr[j])
		swap(arr[last], arr[j]);
	qsort(first, i);
	qsort(j, last);
}

int main() {
	int a;
	cin >> a;
	for (int i = 0; i < a; i++)
		cin >> arr[i];
	qsort(0, a - 1);
	for (int i = 0; i < a; i++)
		cout << i << "번째 숫자 : " << arr[i] << "\n";
	return 0;
}