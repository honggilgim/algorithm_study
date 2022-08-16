#include <iostream>
#define MAX 51

using namespace std;
int N, M;
int arr[MAX][MAX] = {1,};
bool visited[MAX][MAX];
int ans;

void visit(int x, int y,int d, int count)
{
	if ( x > 0 && d == 0 && arr[x - 1][y] == 0 && visited[x-1][y] == false)
	{
		visited[x - 1][y] = true;
		visit(x - 1, y, 3, count + 1);
		return;
	}
	if (d == 0 && (arr[x - 1][y] == 1 || visited[x - 1][y] == true))
	{
		visit(x, y, 3, count);
		return;
	}
	if (d == 1 && arr[x][y - 1] == 0 && visited[x][y - 1] == false)
	{
		visited[x][y-1] = true;
		visit(x, y - 1, 0, count + 1);
		return;
	}
	if (d == 1 && (arr[x][y-1] == 1 || visited[x][y-1] == true))
	{
		visit(x, y, 0, count);
		return;
	}
	if (d == 2 && arr[x + 1][y] == 0 && visited[x + 1][y] == false)
	{
		visited[x + 1][y] = true;
		visit(x + 1, y, 1, count + 1);
		return;
	}
	if (d == 2 && (arr[x + 1][y] == 1 || visited[x + 1][y] == true))
	{
		visit(x, y, 1, count);
		return;
	}
	if (d == 3 && arr[x][y + 1] == 0 && visited[x][y + 1] == false)
	{
		visited[x][y + 1] == true;
		visit(x, y + 1, 2, count + 1);
		return;
	}
	if (d == 3 && (arr[x][y + 1] == 1 || visited[x][y + 1] == true))
	{
		visit(x, y, 2, count);
		return;
	}
	else
	{
		if (d == 0 && arr[x][y + 1] == 0)
		{
			visit(x, y + 1, 0, count);
			return;
		}
		if (d == 1 && arr[x - 1][y] == 0)
		{
			visit(x - 1, y, 1, count);
			return;
		}
		if (d == 2 && arr[x][y - 1] == 0)
		{
			visit(x, y - 1, 0, count);
			return;
		}
		if (d == 3 && arr[x + 1][y] == 0)
		{
			visit(x + 1, y, 3, count);
			return;
		}
		else
		{
			ans = count;
			return;
		}
	}
}

int main() {
	int x, y;
	int d; // d : 방향
	//d 0 북쪽 1 동쪽 2 남쪽 3 서쪽
	cin >> N >> M;
	cin >> x >> y >> d;
	// N 세로 M 가로
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
			cin >> arr[i][j];
	visited[x][y] == true;
	visit(x, y, d, 1);
	cout << ans;
	return 0;


}