#include <iostream>
#include <vector>
#include <queue>

#define MAX 9
using namespace std;

int N;
bool visited[MAX];
void make(int count,vector<int> answer)
{
	if (count == N)
	{
		for (int i = 0; i < N; i++)
		{
			cout << answer[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 1; i <= N; i++)
	{
		if (visited[i]) continue;
		visited[i] = true;
		answer[count] = i;
		make(count + 1, answer);
		visited[i] = false;
	}
}

int main() {
	
	cin >> N;
	vector<int> answer(N);
	make(0, answer);

	return 0;
}