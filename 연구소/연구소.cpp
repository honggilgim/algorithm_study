#include <iostream>
#include <queue>
#define MAX 10

int map[MAX][MAX];
using namespace std;

int N, M;
int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };
bool visited[MAX][MAX];
queue<pair<int, int>> q;

void bfs() {
	while (!q.empty())
	{
		int a = q.front().first;
		int b = q.front().second;
		visited[a][b] = true;

		for (int i = 0; i <= 4; i++)
		{
			int a1 = a + dx[i];
			int b1 = b + dy[i];

			if (map[a1][b1] == 0 && visited[a1][b1] == false)
			{
				q.push(make_pair(a1, b1));
				visited[a1][b1] = true;
			}
		}
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 2)
				q.push(make_pair(i, j));
		}
	}


}

