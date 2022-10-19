	#include <iostream>
	#include <queue>
	#include <vector>
	#include <deque>
	#include <algorithm>
	#include <string>

	using namespace std;

	// R : 배열의 수의 순서를 뒤집는 함수
	// D : 첫 번째 수를 버리는 함수 비어있으면 에러
	// 함수 조합 가능

	int main() {
		int T;	
		cin >> T;

		for (int i = 0; i < T; i++)
		{
			deque<int> dq;
			string a,b; // a : 명령어, b : 숫자 배열
			int n;
			cin >> a;
			cin >> n;
			cin >> b;
			string temp = ""; // 2자리 이상이면 안됨
			// 입력부분
			for (int k = 0; k < b.length(); k++)
			{
				if (b[k] == '[')
					continue;
				else if ('0' <= b[k] && b[k] <= '9')
					temp += b[k];
				else if (b[k] == ',' || b[k] == ']')
				{
					if (!temp.empty())
					{
						dq.push_back(stoi(temp));
						temp.clear();
					}
				}
			}
			bool err = false; // 에러 여부
			bool back = false; // 뒤집힘 여부

			for (int k = 0; k < a.length(); k++)
			{
				if (a[k] == 'R')
					back = !back;
				else // D
				{
					if (dq.empty())
					{
						err = true;
						cout << "err\n";
						break;
					}
					else
					{
						if (!back)
							dq.pop_front();
						else
							dq.pop_back();
					}


				}
			}
			// 출력
			if (!err) //에러가 아니고,
			{
				if (!back) // 뒤집혀져있지 않다면,
				{
					cout<< "[";
					while (!dq.empty())
					{
						cout<< dq.front();
						dq.pop_front();
						if (!dq.empty())
							cout<< ",";
					}
					cout<< "]\n";
				}
				else
				{
					cout<< "[";
					while (!dq.empty())
					{
						cout<< dq.back();
						dq.pop_back();
						if (!dq.empty())
							cout<< ",";
					}
					cout<< "]\n";
				}
			}
		}

		return 0;

	}