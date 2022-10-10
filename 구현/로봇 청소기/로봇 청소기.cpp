#include <iostream>
#define MAX 51

using namespace std;
int N, M;
int arr[MAX][MAX];
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };

void visit(int x, int y,int d, int count)
{
	if (count >= 4) {
		int nx = x - dx[d];
		int ny = y - dy[d];
		if (nx >= 0 && nx < N && ny >= 0 && ny < M && arr[nx][ny] == 2)
			visit(nx, ny, d, 0);
		return;
	}
	arr[x][y] = 2;
	int nd = ((d - 1) + 4) % 4;
	int nx = x + dx[nd];
	int ny = y + dy[nd];
	if (nx >= 0 && nx < N && ny >= 0 && ny < M)
	{
		if (arr[nx][ny] == 0)
			visit(nx, ny, nd, 0);
		else if (arr[nx][ny] == 1 || arr[nx][ny] == 2)
			visit(x, y, nd, count + 1);
	}

}

int main() {
	int ans = 0;
	int x, y;
	int d; // d : 방향
	//d 0 북쪽 1 동쪽 2 남쪽 3 서쪽
	cin >> N >> M;
	cin >> x >> y >> d;
	// N 세로 M 가로
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> arr[i][j];
	visit(x, y, d, 0);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (arr[i][j] == 2)
				ans++;
	cout << ans << "\n";
	return 0;
}