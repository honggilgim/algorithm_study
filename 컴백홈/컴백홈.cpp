#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#define MAX 6

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

using namespace std;
int R, C, K;
char map[MAX][MAX];
bool visited[MAX][MAX];

int ans;

void dfs(int x, int y, int count) {
	if (x == 0 && y == C-1 && count == K)
	{
		ans++;
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < R && ny >= 0 && ny < C && map[nx][ny] == '.' && visited[nx][ny] == false)
		{
			visited[nx][ny] = true;
			dfs(nx, ny, count + 1);
			visited[nx][ny] = false;
		}
	}
}

int main() {
	cin >> R >> C >> K;
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			cin >> map[i][j];
	visited[R - 1][0] = true;
	dfs(R - 1, 0, 1);
	cout << ans;
	return 0;
}