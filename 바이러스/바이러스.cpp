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
	for (int i = 0; i <= N; i++)
	{
		if (map[a][i] == 1 && visited[i] == false)
		{
			//cout << a << i << "\n";
			cot++;
			dfs(i);
		}
	}
}

void bfs(int a) {
	visited[a] = true;
	queue <int> q;
	q.push(a);
	while (!q.empty())
	{
		int k = q.front();
		q.pop();
		for (int i = 0; i <= N; i++)
		{
			if (map[k][i] == 1 && visited[i] == false)
			{
				q.push(i);
				visited[i] = true;
				cot++;
			}
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
	bfs(1);

	cout << cot;

	return 0;

}