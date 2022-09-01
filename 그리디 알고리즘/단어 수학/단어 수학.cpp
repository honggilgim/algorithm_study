#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int N;
	int arr[26] = { 0 };
	cin >> N;
	vector<string> a;
	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;
		a.push_back(s);
	}
	for (int i = 0; i < a.size(); i++)
	{
		int k = 1;
		for (int j = a[i].size()-1; j >= 0; j--)
		{
			arr[(a[i][j] - 'A')] += k;
			k *= 10;
		}
	}
	sort(arr, arr + 26);
	int val = 9;
	int answer = 0;
	for (int i = 25; i >= 0; i--)
	{
		if (arr[i] == 0)
			break;
		answer += (arr[i] * val);
		val--;
	}
	cout << answer;
	return 0;
}