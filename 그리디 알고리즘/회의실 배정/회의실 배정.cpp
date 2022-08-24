#include <iostream>
#include<queue>
#include <algorithm>
#include <vector>
#define MAX 11



using namespace std;

int main() {
	int N;
	cin >> N;
	vector <pair< int, int >> meeting;
	for (int i = 0; i < N; i++)
	{
		int a, b;
		cin >> a >> b;
		meeting.push_back({ b,a });
	}
	sort(meeting.begin(), meeting.end());

	int start = 0;
	int ans = 0;
	for (int i = 0; i < N; i++)
	{
		if (start <= meeting[i].second)
		{
			ans++;
			start = meeting[i].first;
		}
	}

	cout << ans;
	return 0;
}