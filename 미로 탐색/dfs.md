```
bool visited[MAX][MAX];
int arr[MAX][MAX];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int m = 1000000;
int N, M;

using namespace std;

void dfs(int a, int b,int count)
{
	if (a < 0 || b < 0 || a >= N || b >= M) return;
	if (a == N - 1 || b == M - 1)
	{
		if (count < m)
			m = count;
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		int na = a + dx[i];
		int nb = b + dy[i];
		if (visited[na][nb] == 0 && arr[na][nb] == '1')
		{
			visited[na][nb] = 1;
			dfs(na, nb, count + 1);
			visited[na][nb] = 0;
		}
	}

}

int main() {

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; i < M; j++)
		{
			cin >> arr[i][j];
		}
	}

	dfs(0, 0, 1);
	
	cout << m << "\n";

	return 0;

}
```

dfs로 시도했던 문제풀이
