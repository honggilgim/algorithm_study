#include <iostream>
using namespace std;

int asd(int a, int b) {
	if (a > b)
		return b;
	else
		return a;
}

int main()
{
	int T;
	cin >> T;
	int* max_arr = new int[T+5];
	int* min_arr = new int[T+5];
	for (int i = 1; i <= T; i++)
	{
		int n, a, b;
		cin >> n >> a >> b;
		max_arr[i] = asd(a, b);
		if (n > (a + b))
		{
			min_arr[i] = 0;
		}
		else
		{
			min_arr[i] = (a + b - n);
		}
	}
	for (int i = 1; i <= T; i++)
	{
		cout << "#" << i << " " << max_arr[i] << " " << min_arr[i] <<"\n";
	}
	delete[] max_arr;
	delete[] min_arr;
	return 0;
}