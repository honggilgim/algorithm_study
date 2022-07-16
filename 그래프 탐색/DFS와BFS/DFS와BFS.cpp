#include <iostream>
#include <queue>
#include <vector>
#define MAX 1001

using namespace std;

int N, M, V;
int map[MAX][MAX];
bool visited[MAX];
queue<int> q;

void dfs(int a) {
	visited[a] = true;
	cout << a << " ";
	for (int i = 1; i <= N; i++)
	{
		if (map[a][i] == 1 && visited[i] == 0)
		{
			dfs(i);
		}
	}
}

void bfs(int a)
{
	q.push(a);
	visited[a] = true;
	cout << a << " ";

	while (!q.empty())
	{
		a = q.front();
		q.pop();

		for (int i = 1; i <= N; i++)
		{
			if (map[a][i] == 1 && visited[i] == 0)
			{
				q.push(i);
				visited[i] = true;
				cout << i << " ";
			}
		}
	}
}



int main() {
	cin >> N >> M >> V;

	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		map[a][b] = 1;
		map[b][a] = 1;
	}

	for (int i = 1; i <= N; i++)
		visited[i] = false;

	dfs(V);
	cout << "\n";

	for (int i = 1; i <= N; i++)
		visited[i] = false;

	bfs(V);

	return 0;
}