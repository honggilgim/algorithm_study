#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>

#define MAX 10

using namespace std;
int n, m;
string map[MAX][MAX];
bool visited[MAX][MAX][MAX][MAX];

struct ballindex
{
	int rx;
	int ry;
	int bx;
	int by;
};

queue <ballindex> q;

int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

int ball(int& x, int& y, int i)
{
	int count = 1;
	while ((map[x + dx[i]][y + dy[i]] != "#") && (map[x][y] != "O"))
	{
		x += dx[i];
		y += dy[i];
		count++;
	}
	return count;
}

int bfs()
{
	int cot = -1;
	while (!q.empty())
	{
		if (cot > 10)
			return -1;
		int rx = q.front().rx;
		int ry = q.front().ry;
		int bx = q.front().bx;
		int by = q.front().by;
		cot++;
		cout << " rx : " << rx << " ry :" << ry << " bx : " << bx << " by : " << by << "cot : " << cot << "\n";
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int rrx = rx;
			int rry = ry;
			int bbx = bx;
			int bby = by;
			int redmove = 0;
			int bluemove = 0;

			redmove = ball(rrx, rry,i);
			cout << "rrx : " << rrx << "rry : " << rry << "i :  " << i << "\n";
			bluemove = ball(bbx, bby, i);
			cout << "bbx : " << bbx << "bby : " << bby << "i :  " << i << "\n\n";
			if (map[bbx][bby] == "O") continue;
			if (map[rrx][rry] == "O")
			{
				cout << rrx << rry << "\n";
				cout << "성공!";
				return cot;
			}
			if (rrx == bbx && rry == bby)
			{
				if (redmove > bluemove)
				{
					rrx -= dx[i];
					rry -= dy[i];
				}
				else
				{
					bbx -= dx[i];
					bby -= dy[i];
				}
			}
			if (visited[rrx][rry][bbx][bby]) continue;
			visited[rrx][rry][bbx][bby] = true;
			
			q.push({ rrx,rry,bbx,bby });
		}
	}
}

int main() {
	//n 세로 m 가로
	cin >> n >> m;
	int bx, by;
	int rx, ry;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < m; j++)
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
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}

	//cout << " rx : " << rx << " ry :" << ry << " bx : " << bx << " by : " << by <<"\n";

	q.push({ rx, ry, bx, by });
	cout << bfs();

	return 0;

}
