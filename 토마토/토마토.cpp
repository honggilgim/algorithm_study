#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#define MAX 1001
using namespace std;

int M, N;
int map[MAX][MAX];
int cot;
vector<int> answer;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
queue<pair<int, int>> q;

void bfs()
{
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && nx < N && ny >= 0 && ny < M && map[nx][ny] == 0)
			{
				map[nx][ny] = map[x][y]+1;
				q.push(make_pair(nx, ny));
			}

		}
	}
}

int main()
{
	cin >> M >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 1)
			{
				q.push(make_pair(i, j));
			}
		}
	}

	bfs();
	/*
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
	*/
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 0) {
				printf("-1\n");
				return 0;
			}
			if (cot < map[i][j]) {
				cot = map[i][j];
			}
		}
	}
	cout << (cot-1);
	return 0;
}
