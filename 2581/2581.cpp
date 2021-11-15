#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int a, b;
	int minc = 100000;
	int sc=0;
	int sum = 0;

	cin >> a >> b;

	for (int i = a; i <= b; i++)
	{
		int count = 0;
		if (i == 1)
			continue;
		for (int k = 2; k < i; k++)
		{
			if (i % k == 0)
				count++;
		}
		if (count == 0)
		{
			sc++;
			sum += i;
			minc = min(minc, i);
		}
	}
	if (sc == 0)
		cout << "-1";
	else {
		cout << sum << "\n" << minc;
	}
	return 0;
}