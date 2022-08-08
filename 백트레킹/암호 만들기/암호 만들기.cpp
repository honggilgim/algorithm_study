#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 16
int L, C;
string s[MAX];
bool visited[MAX];

// 최소 두 개의 자음과 한 개의 모음
// 암호에서 증가하는 순서로 배열
void print(int a, vector<string> answer,int mo, int ja) {
	if (a == L && mo >= 1 && ja >= 2)
	{
		for (int i = 0; i < L; i++)
		{
			cout << answer[i];
		}
		cout << "\n";
		return;
	}
	for (int i = 0; i < C; i++)
	{
		if (visited[i]) continue;
		if (a > 0)
		{
			if(answer[a - 1] > s[i])
				continue;
		}
		answer[a] = s[i];
		if (s[i] == "a" || s[i] == "e" || s[i] == "i" || s[i] == "o" || s[i] == "u")
		{
			mo++;
			visited[i] = true;
			print(a + 1, answer, mo, ja);
			mo--;
		}
		else
		{
			ja++;
			visited[i] = true;
			print(a + 1, answer, mo, ja);
			ja--;
		}
		//cout << "a : " << a << " s[i]" << s[i] << "모음" << mo << "자음" << ja << "\n";
		visited[i] = false;
	}


}

int main()
{
	cin >> L >> C;
	vector<string> answer(MAX);
	for (int i = 0; i < C; i++)
	{
		cin >> s[i];
	}
	sort(s, s + C);
	print(0, answer, 0, 0);
	return 0;
}