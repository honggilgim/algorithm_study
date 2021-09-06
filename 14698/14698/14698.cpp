#include <iostream>
#include<algorithm>
#include <queue>
using namespace std;
long long int vix = 1000000007;

int main() {
	int b;
	cin >> b;
	queue <long long int> q;
	for (int i = 0; i < b; i++)
	{
		int a;
		long long int value = 1;

		long long int arr[61];
		cin >> a;
		for (int k = 0; k < a; k++)
		{
			cin >> arr[k];
		}
		for (int k = 0; k < a - 1; k++)
		{
			sort(arr + k, arr + a);
			arr[k + 1] = arr[k] * arr[k + 1];
			value = (value * (arr[k + 1]%vix))%vix;
		}
		if (a == 1)
			value = 1;
		q.push(value);
	}
	while (!q.empty())
	{
		cout << q.front() << "\n";
		q.pop();
	}
	return 0;
}