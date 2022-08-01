#include <iostream>
#include <queue>

#define MAX 51

using namespace std;
int map[MAX][MAX];
bool visited[MAX][MAX];
int dx[] = { 0,1,0,-1,1,-1,1,-1 };
int dy[] = { 1,0,-1,0,-1,1,1,-1 };

int W, H;
queue<pair<int, int>> q;

void bfs(int a, int b)
{
	q.push(make_pair(a, b));
	//cout << "bfs 시작 : " << a << " " << b << "\n";
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		//cout << "bfs 과정 : " << x << " " << y << "\n";
		for (int i = 0; i < 8; i++)
		{
			int x1 = x + dx[i];
			int y1 = y + dy[i];
			if (x1 > -1 && x1 < H && y1 > -1 && y1 < W && visited[x1][y1] == false && map[x1][y1] == 1)
			{
				visited[x1][y1] = true;
				q.push(make_pair(x1,y1));
			}
		}
	}
}

int main() {
	queue<int> ans;
	while (1)
	{
		cin >> W >> H;
		if (W == 0 && H == 0)
			break;
		for (int i = 0; i < H; i++)
		{
			for (int j = 0; j < W; j++)
			{
				cin >> map[i][j];
			}
		}
		int island = 0;
		for (int i = 0; i < H; i++)
		{
			for (int j = 0; j < W; j++)
			{
				if (map[i][j] == 1 && visited[i][j] == false)
				{
					bfs(i, j);
					//cout << "bfs 입장 : " << i << " " << j << "\n";
					island++;
				}
			}
		}

		//cout << "island : " << island << "\n";

		ans.push(island);
		island = 0;

		for (int i = 0; i < H; i++)
		{
			for (int j = 0; j < W; j++)
			{
				map[i][j] = 0;
				visited[i][j] = false;
			}
		}
		
	}

	while (!ans.empty())
	{
		cout << ans.front() << "\n";
		ans.pop();
	}

	return 0;
}

