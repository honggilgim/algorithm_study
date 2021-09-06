/*
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#define endl "\n"
using namespace std;
string arr[6][6];
int r, c, k;
int answer = 0;
// a 세로 b 가로
void find_root(int a, int b, int s) {
	if (a > 1 && arr[a - 1][b] == ".")
	{
		find_root(a - 1, b, s + 1);
	}
	if (b < c && arr[a][b + 1] == ".")
	{
		find_root(a, b + 1, s + 1);
	}
	if (a == 1 && b == c)
	{
		answer++;
	}
}
// r 세로 c 가로
int main() {
	cin >> r >> c >> k;
	for (int i = 1; i < r+1; i++)
	{
		for (int k = 1; k < c+1; k++)
			cin >> arr[i][k];
	}
	find_root(r, 1, 0);
	cout << answer << endl;
	return 0;
}
*/

/*
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#define endl "\n"
using namespace std;
string arr[6][6];
int visited[6][6];
int r, c, k;
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
int answer = 0;
// a 세로 b 가로
void find_root(int a, int b, int s) {
	if (a == 1 && b == c && s == k)
	{
		answer++;
		return;
	}
	for (int i = 0; i < 4; i++) {
		int nx = a + dx[i];
		int ny = b + dy[i];
		if (arr[nx][ny] == "T") continue;
		if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
		if (visited[nx][ny]) continue;
		visited[nx][ny] = 1;
		find_root(nx, ny, s + 1);
		visited[nx][ny] = 0;

	}
}
// r 세로 c 가로
int main() {
	cin >> r >> c >> k;
	for (int i = 1; i < r + 1; i++)
	{
		for (int k = 1; k < c + 1; k++)
			cin >> arr[i][k];
	}
	visited[r][1] = 1;
	find_root(r, 1, 0);
	cout << answer << endl;
	return 0;
}
*/

#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
char arr[6][6];
int vs[6][6];
int r, c, k, ans;

void find_root(int x, int y, int distance) {
    if (distance == k && x == 0 && y == c - 1)
    {
        ans++; return;
    }
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (arr[nx][ny] == 'T') continue;
        if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue; // 조건.
        if (vs[nx][ny]) continue;
        vs[nx][ny] = 1;
        find_root(nx, ny, distance + 1);
        vs[nx][ny] = 0;
    }
}

int main() {
	ans = 0;
    cin >> r >> c >> k;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> arr[i][j];
    vs[r - 1][0] = 1;
    find_root(r - 1, 0, 1);
    cout << ans << '\n';
	return 0;
}

