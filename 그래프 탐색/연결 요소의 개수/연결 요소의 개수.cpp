#include <iostream>
#include <queue>
#define MAX 1001
using namespace std;

int arr[MAX][MAX];
bool visited[MAX];
int N, M;
queue<int> q;
void bfs(int a) {
	q.push(a);
	visited[a] = true;
	while (!q.empty())
	{
		int a = q.front();
		q.pop();

		for (int i = 1; i <= N; i++)
		{
			if (arr[a][i] == 1 && arr[i][a] == 1 && visited[i] == false)
			{
				q.push(i);
				visited[i] = true;
			}
		}
	}
}

int main() {
	int cot = 0;
	cin >> N >> M;

	int a, b;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		arr[a][b] = 1;
		arr[b][a] = 1;
	}
	for (int i = 1; i <= N; i++)
	{
		if (visited[i] == false)
		{
			bfs(i);
			cot++;
		}
	}

	cout << cot;

	return 0;
}