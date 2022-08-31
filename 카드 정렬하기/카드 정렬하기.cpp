#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
/*
int main()
{
	int N;
	cin >> N;
	vector<int> card;
	for (int i = 0; i < N; i++)
	{
		int x;
		cin >> x;
		card.push_back(x);
	}
	int answer = 0;
	while (card.size() > 1)
	{
		sort(card.begin(), card.end());
		answer += card[0] + card[1];
		card[1] = card[0] + card[1];
		card.erase(card.begin());
		//cout << answer << endl;
	}
	cout << answer;
	return 0;
}
*/

int main() {
	priority_queue<int, vector<int>, greater<int>> q;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int x;
		cin >> x;
		q.push(x);
	}
	int answer = 0;
	while (q.size() > 1)
	{
		int a, b;
		a = q.top();
		q.pop();
		b = q.top();
		q.pop();
		answer += (a + b);
		q.push(a + b);
	}
	cout << answer;
	return 0;
}