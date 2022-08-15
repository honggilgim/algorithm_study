#include <iostream>
#include <algorithm>
#define MAX 501

using namespace std;


int M, N;
int arr[MAX][MAX];
bool visited[MAX][MAX];
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
int minv = 0;

void checkscore(int x, int y, int count, int score)
{
	score += arr[x][y];
	if (count == 4)
	{
		minv = max(minv, score);
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < N && ny >= 0 && ny < M && visited[nx][ny] == false)
		{
			visited[nx][ny] = true;
			checkscore(nx, ny, count + 1, score);
			visited[nx][ny] = false;
		}
	}
}

void checkother(int x, int y)
{
	if(x-1 >=0 && y+2 < M)
		minv = max(minv, arr[x][y] + arr[x][y+1] + arr[x][y+2] + arr[x-1][y+1]);
	if (x+1 < N && y+2 < M)
		minv = max(minv, arr[x][y] + arr[x][y+1] + arr[x][y+2] + arr[x+1][y+1]);
	if(x+2 < N && y+1 < M)
		minv = max(minv, arr[x][y] + arr[x+1][y] + arr[x+2][y] + arr[x+1][y+1]);
	if (x + 1 < N && x - 1 >= 0 && y + 1 < M)
		minv = max(minv, arr[x][y] + arr[x - 1][y + 1] + arr[x][y + 1] + arr[x + 1][y + 1]);
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			checkother(i, j);
			visited[i][j] = true;
			checkscore(i, j, 1, 0);
			visited[i][j] = false;
		}
	}
	cout << minv;
	return 0;
}