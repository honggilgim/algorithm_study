#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int T;
	cin >> T;
	vector<int> an;
	for (int i = 0; i < T; i++)
	{
		int N;
		vector<pair<int, int>> a;
		cin >> N;
		for (int k = 0; k < N; k++)
		{
			int b, c;
			cin >> b >> c;
			a.push_back({ b,c });
		}
		sort(a.begin(), a.end());
		int ans = 0;
		int max = a[0].second;
		for (int i = 0; i < N; i++)
		{
			if (a[i].second <= max)
			{
				ans++;
				max = a[i].second;
			}
		}
		an.push_back(ans);

	}
	for (int i = 0; i < T; i++)
	{
		cout << an[i] << endl;
	}
	return 0;
}