#include<iostream>
#include <cstdio>
#include<queue>
using namespace std;
int arr2[500000] = { 0 };

void swap(int* arr, int a, int b) {
	int tmp = arr[a];
	arr[a] = arr[b];
	arr[b] = tmp;
}

void qsort(int* arr, int start, int end) {
	int pivot = arr[start];
	int left = start + 1;
	int right = end;

	while (left <= right) {

		while (arr[left] < pivot) { left++; }
		while (arr[right] > pivot) { right--; }

		if (left <= right) { swap(arr, left, right); }
	}


	if (start < end) {
		swap(arr, start, right);
		qsort(arr, start, right - 1);
		qsort(arr, right + 1, end);
	}
}

int main() {
	int a;
	int c=0, d=0, e=0, max=0,min=0, sum = 0;
	double b;
	cin >> a;
	int* arr = new int[a + 5];
	int* arr2 = new int[a];
	for (int i = 0; i < a; i++)
		arr2[i] = 0;
	for (int i = 0; i < a; i++)
	{
		cin >> arr[i];
		sum += arr[i];
		arr2[a]++;
		if (arr[a] >= max)
			max = arr[a];
		else if (arr[a] <= min)
			min = arr[a];
	}
	b = sum / a; //%1f 기억하기

	qsort(arr, 0, a);
	
	arr[a / 2] = c;
	d = arr2[1];
	for (int i = 0; i < a; i++)
	{
		if (arr2[i] > d)
			d = arr2[i];
	} // 최빈값
	e = max - min;
	printf("%.1f", b);
	cout << c << "\n";
	cout << d << "\n";
	cout << e << "\n";

	delete[]arr;
	delete[]arr2;

	return 0;
}