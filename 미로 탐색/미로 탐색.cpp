#include <iostream>
#include <queue>
#include <string>
#define MAX 101
using namespace std;

int N, M;
int check[MAX][MAX];
bool visited[MAX][MAX];
int map[MAX][MAX];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
queue<pair<int, int>> q;

void bfs(int x, int y)
{
	visited[x][y] = true;

	q.push(make_pair(x, y));

	check[x][y]++;

	while (!q.empty());
	{
		int x = q.front().first;
		int y = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && nx < N && ny >= 0 && ny < M && map[nx][ny] == 1 && visited[nx][ny] == false)
			{
				visited[nx][ny] = true;
				q.push(make_pair(nx, ny));
				check[nx][ny] = check[x][y] + 1;
			}
		}
	}
}



int main()
 {
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < M; j++)
		{
			map[i][j] == s[j] - '0';
		}
	}

	bfs(0, 0);
	
	cout << check[N - 1][M - 1];
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << check[i][j];
		}
		cout << "\n";
	}
	cout << "맵" << "\n";
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << map[i][j];
		}
		cout << "\n";
	}
	
	return 0;

}