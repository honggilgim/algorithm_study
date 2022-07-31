#include <iostream>
#include <queue>
#include <algorithm>
#define MAX 10

int map[MAX][MAX];
using namespace std;
int map2[MAX][MAX];
int map3[MAX][MAX];
bool visited[MAX][MAX];
int ans;

int N, M;
int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };
queue<pair<int, int>> q;
int test;

void bfs() {
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			map3[i][j] = map2[i][j];
			visited[i][j] = false;
		}
	}
	//cout << "bfs 전 : \n";
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map3[i][j] == 2)
				q.push(make_pair(i, j));
			//cout << map3[i][j] << " ";
		}
		//cout << "\n";
	}

	while (!q.empty())
	{
		int a = q.front().first;
		int b = q.front().second;
		q.pop();
		visited[a][b] = true;

		for (int i = 0; i <= 3; i++)
		{
			int a1 = a + dx[i];
			int b1 = b + dy[i];

			if (a1 > -1 && a1 < N && b1 > -1 && b1 < M && map3[a1][b1] == 0 && visited[a1][b1] == false)
			{
				visited[a1][b1] = true;
				map3[a1][b1] = 2;
				q.push(make_pair(a1, b1));
			}
		}
	}
	//cout << "bfs 결과 : \n";
	int cnt = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map3[i][j] == 0)
				cnt++;
			//cout << map3[i][j] << " ";
		}
		//cout << "\n";
	}
	//cout << "cnt 결과 : " << cnt << "\n";
	ans = max(ans, cnt);
	test++;
}

void copy() {
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			map2[i][j] = map[i][j];
		}
	}
}

void wall(int a)
{
	if (a == 3)
	{
		bfs();
		return;
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map2[i][j] == 0)
			{
				map2[i][j] = 1;
				wall(a + 1);
				map2[i][j] = 0;
			}
		}
	}

}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 0) {
				copy();
				map2[i][j] = 1;
				wall(1);
				map2[i][j] = 0;
			}
		}
	}
	cout << ans;

	//cout << "bfs 수행 횟수 :" << test;

	return 0;

}
