#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 55

using namespace  std;

bool visited[MAX][MAX];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int map[MAX][MAX];

queue<pair<int, int>> q;

void bfs(int x, int y,int M, int N)
{
	visited[x][y] = true;

	q.push(make_pair(x, y));
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && ny >= 0 && nx < M && ny < N && map[nx][ny] == 1 && visited[nx][ny] == false)
			{
				visited[nx][ny] = true;
				q.push(make_pair(nx, ny));
			}
		}
	}
}

void clear() {
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			map[i][j] = 0;
			visited[i][j] = false;
		}
	}
}

int main() {
	vector<int> answer;
	int T, M, N, K, count;
	int number = 0;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		count = 0;
		cin >> M >> N >> K;
		for (int j = 0; j < K; j++)
		{
			int x, y;
			cin >> x >> y;
			map[x][y] = 1;
		}
		for (int j = 0; j < M; j++)
		{
			for (int h = 0; h < N; h++)
			{
				if (map[j][h] == 1 && visited[j][h] == false)
				{
					bfs(j, h, M, N);
					count++;
				}
			}
		}

		answer.push_back(count);
		clear();

	}

	for (int i = 0; i < T; i++)
		cout << answer[i] << "\n";
	return 0;
}