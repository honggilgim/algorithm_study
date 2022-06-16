#include <iostream>
#include <algorithm>
#include <queue>
using namepsace std;

int main() {
	int T;
	queue <int>q;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int a;
		cin >> a;
		int* arr = new int[a];
		int* arrtwo = new int[a];
		for (int k = 0; k < a; k++)
		{
			cin >> arr[k];
			arrtwo[k] = arr[k];
		}
		sort(arrtwo[0], arrtwo[a-1]);
		int max_value = 0;
		for (int k = 0; k < a; k++)
		{
			for (int j = 0; j < a; j++)
			{
				if (arr[j] == arrtwo[k])
					break;
				else
					max_value += arrtwo[k] - arr[j];
			}
		}
		q.push(max);
	}

	return 0;

}