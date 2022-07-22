#include <iostream>
#include <queue>
#define MAX 101
using namespace std;

int cot;
int N, M;
int map[MAX][MAX];
bool visited[MAX];

void dfs(int a) {
	visited[a] = true;
	cot++;
	for (int i = 0; i <= N; i++)
	{
		if (map[a][i] == 1 && visited[i] == false)
		{
			//cout << a << i << "\n";
			dfs(i);
		}
	}
}



int main()
{
	int a, b;
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		map[a][b] = 1;
		map[b][a] = 1;
	}
	dfs(1);

	cout << (cot-1);

	return 0;

}