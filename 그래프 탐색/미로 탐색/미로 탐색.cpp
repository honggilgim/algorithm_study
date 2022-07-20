#include <iostream>
#include <queue>
#include <string>
#define MAX 101
using namespace std;

int N, M;
int check[MAX][MAX] = { 0 };
int visited[MAX][MAX] = { 0 };
int map[MAX][MAX] = { 0 };
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
queue<pair<int, int>> q;

void bfs(int x, int y)
{
	visited[x][y] = 1;

	q.push(make_pair(x, y));

	check[x][y]++;

	//cout << "작동";

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		//cout << "작동";

		q.pop();
		//cout << "작동";

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			//cout << "작동";

			if (nx >= 0 && nx < N && ny >= 0 && ny < M && map[nx][ny] == 1 && visited[nx][ny] == 0)
			{
				visited[nx][ny] = 1;
				//cout << "작동";
				q.push(make_pair(nx, ny));
				check[nx][ny] = check[x][y] + 1;
			}
			//cout << "작동";
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
			map[i][j] = s[j] - '0';
		}
	}

	/*cout << "맵" << "\n";
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << map[i][j];
		}
		cout << "\n";
	}
	cout << "\n";
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << check[i][j];
		}
		cout << "\n";
	}
	*/

	bfs(0, 0);

	//cout << "작동";
	
	int k;
	k = check[N - 1][M - 1];
	cout << k << "\n";

	cout << "check 배열 \n";
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << check[i][j] << "   ";
		}
		cout << "\n";
	}
	
	
	return 0;

}

