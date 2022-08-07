#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;
#define MAX 16
int arr[MAX];
int N;
int cnt;
//퀸의 공격 방향 : 좌우 대각선, 위아래 직선

//퀸이 공격받지 않으려면, 한 행당 한 개의 퀸을 배치할 수 있음
bool check_value(int a)
{
	for (int i = 0; i < a; i++)
	{
		//arr[i] == arr[a] 같은 라인에 있으면 안됨
		// 배열 안에 있는 값이 x좌표, 밖에 있는 값이 y좌표다.
		if (arr[i] == arr[a] || abs(arr[a] - arr[i]) == abs(a - i))
			return false;
	}
	return true;
}

void count_number(int a)
{
	if (a == N)
		cnt++;
	else
	{
		for (int i = 0; i < N; i++)
		{
			arr[a] = i;
			if (check_value(a))
				count_number(a + 1);
		}
	}
}

int main() {
	cin >> N;
	count_number(0);
	cout << cnt;
	return 0;
}