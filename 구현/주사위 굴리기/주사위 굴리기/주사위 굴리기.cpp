#include <iostream>
#include <queue>
#include <vector>

#define MAX 21

int map[MAX][MAX] ={-1};
using namespace std;

int n, m, x, y, cot;

// 지도 윗면이 1, 동쪽을 바라보는 방향이 3인 상태로 놓여져 있음.

int check(int a)
{
	if (a == 1 && y == m - 1) return 0;
	else if (a == 2 && y == 0) return 0;
	else if (a == 3 && x == 0) return 0;
	else if (a == 4 && x == n - 1) return 0;
	return 1;
}

int main() {
	vector<int> a;
	int dice[6] = { 0 }; // 위 아래 동 서 남 북
	cin >> n >> m >> x >> y >> cot;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < cot; i++)
	{
		int k;
		cin >> k;
		a.push_back(k);
		//1 동 2 서 3 북 4 남
	}

	

	for (int i = 0; i < cot; i++)
	{
		int temp = dice[0];
		//cout << " x :" << x << " y : " << y << endl;

		//if (a[i] == 1 && y == m - 1) continue;
		//if (a[i] == 2 && y == 0) continue;
		//if (a[i] == 3 && x == 0) continue;
		//if ((a[i] == 4) && (x = n - 1)) continue;
		// continue가 왜들어가지?
		if (check(a[i]))
		{
			if (a[i] == 1) {
				y++;
				dice[0] = dice[3];
				dice[3] = dice[1];
				dice[1] = dice[2];
				dice[2] = temp;
			}
			else if (a[i] == 2) {
				y--;
				dice[0] = dice[2];
				dice[2] = dice[1];
				dice[1] = dice[3];
				dice[3] = temp;
			}
			else if (a[i] == 3) {
				x--;
				dice[0] = dice[4];
				dice[4] = dice[1];
				dice[1] = dice[5];
				dice[5] = temp;
			}
			else if (a[i] == 4) {
				x++;
				dice[0] = dice[5];
				dice[5] = dice[1];
				dice[1] = dice[4];
				dice[4] = temp;
			}

			if (map[x][y] == 0) {
				map[x][y] = dice[1];
			}
			else {
				dice[1] = map[x][y];
				map[x][y] = 0;
			}
			cout << dice[0] << endl;
		}
	}
	return 0;

}