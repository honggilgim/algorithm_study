#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	string S;
	string T;
	int answer = 0;

	//문자열 뒤에 A 추가
	// 문자열 뒤집고 B 추가

	cin >> S;
	cin >> T;

	while (true)
	{
		if (S.size() == T.size())
		{
			if (S == T)
				answer = 1;
			break;
		}
		//cout << T[T.size()-1] << "\n";

		if (T[T.size()-1] == 'A')
			T.pop_back();
		else
		{
			T.pop_back();
			reverse(T.begin(), T.end());
		}
	}
	cout << answer;
	return 0;

}