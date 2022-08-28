#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, m;
	long long int ans=0;
	vector<long long int> card;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		long long int a;
		cin >> a;
		card.push_back(a);
	}
	for (int i = 0; i < m; i++)
	{
		long long int s = 0;
		sort(card.begin(), card.end());
		s = card[0] + card[1];
		card[0] = s;
		card[1] = s;
	}
	for (int i = 0; i < card.size(); i++)
	{
		ans += card[i];
	}
	cout << ans;
	return 0;
}