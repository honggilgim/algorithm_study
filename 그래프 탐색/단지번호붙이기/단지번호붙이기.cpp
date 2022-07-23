#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 30

using namespace  std;

int N;
bool visited[MAX][MAX];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
vector<int> answer;

int map[MAX][MAX];

queue<pair<int, int>> q;

void bfs(int x, int y)
{
	visited[x][y] = true;
	int count = 0;

	q.push(make_pair(x, y));
	count++;
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && ny >= 0 && nx < N && ny < N && map[nx][ny] == 1 && visited[nx][ny] == false)
			{
				visited[nx][ny] = true;
				q.push(make_pair(nx, ny));
				count++;
			}
		}
	}

	answer.push_back(count);
}

int main() {
	int number=0;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < N; j++)
			map[i][j] = s[j]-'0';
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (visited[i][j] == false && map[i][j] == 1)
			{
				bfs(i, j);
				number++;
			}
		}
	}

	sort(answer.begin(), answer.end());

	cout << number << "\n";
	for (int i = 0; i < answer.size(); i++)
	{
		cout << answer[i] << "\n";
	}

	return 0;
}