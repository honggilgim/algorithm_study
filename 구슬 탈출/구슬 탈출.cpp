#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>

#define MAX 10

using namespace std;
int n, m;
string map[MAX][MAX];
bool visited[MAX][MAX];

struct ballindex
{
	int rx;
	int ry;
	int bx;
	int by;
};

queue <ballindex> q;

int ans_x, ans_y;

int cot;
int bfs(int rx, int ry, int bx, int by)
{
	q.push({ rx, ry, bx, by });
	visited[rx][ry] = true;
	while (!q.empty())
	{
		if (cot > 10)
			return -1;
		int rx = q.front().rx;
		int ry = q.front().ry;
		if (rx == ans_x && ry == ans_y)
			return cot;
		int bx = q.front().bx;
		int by = q.front().by;
		q.pop();
		int rx_next = rx;
		int bx_next = bx;
		int ry_next = ry;
		int by_next = by;
		bool break_point = false;

		// 오른쪽
		while (map[rx_next][ry_next] != "#" && map[rx_next][ry_next] == "O")
		{
			rx_next++;
		}
		while (map[bx_next][by_next] != "#")
		{
			if (map[bx_next][by_next] == "O")
			{
				break_point = true;
				break;
			}
			bx_next++;
		}
		if (visited[rx_next][ry_next] == false && !break_point)
		{
			visited[rx_next][ry_next] = true;
			q.push({ rx_next,ry_next,bx_next,by_next });
		}

		rx_next = rx;
		bx_next = bx;
		ry_next = ry;
		by_next = by;
		break_point = false;
		//왼쪽
		while (map[rx_next][ry_next] != "#" && map[rx_next][ry_next] == "O")
		{
			rx_next--;
		}
		while (map[bx_next][by_next] != "#")
		{
			if (map[bx_next][by_next] == "O")
			{
				break_point = true;
				break;
			}
			bx_next--;
		}
		if (visited[rx_next][ry_next] == false && !break_point)
		{
			visited[rx_next][ry_next] = true;
			q.push({ rx_next,ry_next,bx_next,by_next });
		}

		rx_next = rx;
		bx_next = bx;
		ry_next = ry;
		by_next = by;
		break_point = false;

		// 위로
		while (map[rx_next][ry_next] != "#" && map[rx_next][ry_next] == "O")
		{
			ry_next++;
		}
		while (map[bx_next][by_next] != "#")
		{
			if (map[bx_next][by_next] == "O")
			{
				break_point = true;
				break;
			}
			by_next++;
		}
		if (visited[rx_next][ry_next] == false && !break_point)
		{
			visited[rx_next][ry_next] = true;
			q.push({ rx_next,ry_next,bx_next,by_next });
		}

		rx_next = rx;
		bx_next = bx;
		ry_next = ry;
		by_next = by;
		break_point = false;

		//아래로
		while (map[rx_next][ry_next] != "#" && map[rx_next][ry_next] == "O")
		{
			ry_next--;
		}
		while (map[bx_next][by_next] != "#")
		{
			if (map[bx_next][by_next] == "O")
			{
				break_point = true;
				break;
			}
			by_next--;
		}
		if (visited[rx_next][ry_next] == false && !break_point)
		{
			visited[rx_next][ry_next] = true;
			q.push({ rx_next,ry_next,bx_next,by_next });
		}

		cot++;

	}
}

int main() {
	//n 세로 m 가로
	cin >> n >> m;
	int bx, by;
	int rx, ry;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == "R")
			{
				rx = i;
				ry = j;
			}
			if (map[i][j] == "B")
			{
				bx = i;
				by = j;
			}
			if (map[i][j] == "O")
			{
				ans_x = i;
				ans_y = j;
			}
		}
	}

	cout << bfs(rx, ry, bx, by);;
}