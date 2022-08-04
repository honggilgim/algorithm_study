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
	cout << "bfs 시작 \n";
	while (!q.empty())
	{
		cout << "1\n";
		if (cot > 10)
			return -1;
		int rx = q.front().rx;
		int ry = q.front().ry;
		int bx = q.front().bx;
		int by = q.front().by;
		q.pop();
		cout << "2\n";
		cout << " rx : " << rx << " ry :" << ry << " bx : " << bx << " by : " << by << " cot :" << cot << "\n";
		if (rx == ans_x && ry == ans_y)
		{
			cout << "성공!";
			return cot;
		}
		int rx_next = rx;
		int bx_next = bx;
		int ry_next = ry;
		int by_next = by;
		bool break_point = false;
		cout << "map[rx_next][ry_next] : " << map[rx_next][ry_next] << " map[rx_next][ry_next] : " << map[rx_next][ry_next] << "3\n" ;
		// 오른쪽
		while (map[rx_next][ry_next] != "#" && map[rx_next][ry_next] != "0")
		{
			rx_next++;
		}
		cout << "4\n";
		while (map[bx_next][by_next] == ".")
		{
			if (map[bx_next][by_next] == "O")
			{
				break_point = true;
				break;
			}
			bx_next++;
		}
		cout << "5" << " R " << rx_next << " b " << bx_next << "\n";
		if (visited[rx_next][ry_next] == false && !break_point)
		{
			cout << "오른쪽 rx : " << rx_next << " ry :" << ry_next << " bx : " << bx_next << " by : " << by_next << "\n";
			visited[rx_next][ry_next] = true;
			q.push({ rx_next,ry_next,bx_next,by_next });
		}

		cout << "6\n";
		rx_next = rx;
		bx_next = bx;
		ry_next = ry;
		by_next = by;
		break_point = false;
		//왼쪽
		while (map[rx_next][ry_next] == "." && map[rx_next][ry_next] != "O")
		{
			rx_next--;
		}
		while (map[bx_next][by_next] == ".")
		{
			if (map[bx_next][by_next] == "O")
			{
				break_point = true;
				break;
			}
			bx_next--;
		}
		cout << "7\n";
		if (visited[rx_next][ry_next] == false && !break_point)
		{
			cout << "왼쪽 rx : " << rx_next << " ry :" << ry_next << " bx : " << bx_next << " by : " << by_next << "\n";
			visited[rx_next][ry_next] = true;
			q.push({ rx_next,ry_next,bx_next,by_next });
		}
		cout << "8\n";
		rx_next = rx;
		bx_next = bx;
		ry_next = ry;
		by_next = by;
		break_point = false;

		// 위로
		while (map[rx_next][ry_next] == "." && map[rx_next][ry_next] != "O")
		{
			ry_next++;
		}
		cout << "9\n";
		while (map[bx_next][by_next] == ".")
		{
			if (map[bx_next][by_next] == "O")
			{
				break_point = true;
				break;
			}
			by_next++;
		}
		cout << "10\n";
		if (visited[rx_next][ry_next] == false && !break_point)
		{
			cout << "위쪽 rx : " << rx_next << " ry :" << ry_next << " bx : " << bx_next << " by : " << by_next << "\n";
			visited[rx_next][ry_next] = true;
			q.push({ rx_next,ry_next,bx_next,by_next });
		}

		rx_next = rx;
		bx_next = bx;
		ry_next = ry;
		by_next = by;
		break_point = false;
		cout << "11\n";
		//아래로
		while (map[rx_next][ry_next] == "." && map[rx_next][ry_next] != "O")
		{
			ry_next--;
		}
		while (map[bx_next][by_next] == ".")
		{
			if (map[bx_next][by_next] == "O")
			{
				break_point = true;
				break;
			}
			by_next--;
		}
		cout << "12\n";
		if (visited[rx_next][ry_next] == false && !break_point)
		{
			cout << "아래쪽 rx : " << rx_next << " ry :" << ry_next << " bx : " << bx_next << " by : " << by_next << "\n";
			visited[rx_next][ry_next] = true;
			q.push({ rx_next,ry_next,bx_next,by_next });
		}
		cout << "13\n";
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
		string s;
		cin >> s;
		for (int j = 0; j < n; j++)
		{
			map[i][j] = s[j];
			
			if (map[i][j] == "R")
			{
				rx = j;
				ry = i;
			}
			if (map[i][j] == "B")
			{
				bx = j;
				by = i;
			}
			if (map[i][j] == "O")
			{
				ans_x = j;
				ans_y = i;
			}
		}
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}

	cout << " rx : " << rx << " ry :" << ry << " bx : " << bx << " by : " << by <<" ans_x : "<< ans_x << " ans_y " << ans_y << "\n";

	cout << bfs(rx, ry, bx, by);

	return 0;

}