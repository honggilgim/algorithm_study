#include <iostream>
#include <stack>
using namespace std;

int fa(int a, int b) {
	if (a == 0)
		return 0;
	int arr[1000];
	int arr2[1000];
	int count = 1;
	while (a >= 1)
	{
		if (a % 2 == 0)
			arr[count] = 0;
		else arr[count] = 1;
		a /= 2;
		count++;
	}
	int k = count;
	for (int i = 0; i < count; i++)
	{
		arr2[i] = arr[k];
		k--;
	}
	for (int i = 1; i < count; i++)
		cout << arr2[i];
	if (b > count)
		return 0;
	for (int i = (count - b)+1; i < count; i++)
	{
		if (arr2[i] == 0)
			return 0;
	}
		return 1;
}

int main()
{
	int a;
	cin >> a;
	int* arr = new int[(a*2) + 1];
	for (int i = 0; i < a * 2; i++)
		cin >> arr[i];
	for (int i = 0; i < a * 2; i += 2)
	{
		int ans = fa(arr[i + 1], arr[i]);
		if (ans)
			cout << "#" << i / 2 + 1 << " ON" << "\n";
		else
			cout << "#" << i / 2 + 1 << " OFF" << "\n";
	}
	delete[]arr;
	return 0;
}