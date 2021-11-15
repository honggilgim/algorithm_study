#include <iostream>
#include <cstdio>
using namespace std;

int range(int a) {
	int count = 0;
	for (int i = 1; i <= a; i++)
	{
		count += i;
		if (count >= a)
		{
			count = i;
			break;
		}
	}
	return count;
}


int main()
{
	int a, b;
	int result = 0;
	cin >> a >> b;
	for (int i = a; i <= b; i++)
	{
		result += range(i);
	}
	cout << result;
	return 0;
}