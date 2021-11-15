#include <iostream>
#include <algorithm>
using namespace std;
int arr[12];
const int MAX = 1000000000;
int max1 = -MAX;
int min2 = MAX;
int a;

void calcu(int value, int count, int plus, int minus, int square, int divide) {
	if (count == a)
	{
		max1 = max(max1, value);
		min2 = min(min2, value);
	}
	if (plus > 0)
		calcu(value + arr[count], count + 1, plus - 1, minus, square, divide);
	if (minus > 0)
		calcu(value - arr[count], count + 1, plus, minus - 1, square, divide);
	if (square > 0)
		calcu(value * arr[count], count + 1, plus, minus, square - 1, divide);
	if (divide > 0)
		calcu(value / arr[count], count + 1, plus, minus, square, divide - 1);
}

int main()
{
	cin >> a;
	for (int i = 0; i < a; i++)
		cin >> arr[i];
	int plus, minus, divide, square;
	cin >> plus >> minus >> square >> divide;
	calcu(arr[0], 1, plus, minus, square, divide);
	cout << max1 << "\n" << min2 << "\n";
	return 0;
}