#include <iostream>
#include <queue>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#define MAX 101
using namespace std;

int N, M;

struct location
{
	int x;
	int y;
};

vector<location> chicken;
vector<location> home;
int distanceanswer = 9999;
bool visited[MAX];
int c, a, b, dis, homechicken,mins;

void choice(int a,vector<int> number)
{
	if (a == M)
	{
		mins = 10000;
		homechicken = 0;
		for (int i = 0; i < home.size(); i++)
		{
			for (int j = 0; j <M; j++)
			{
				c = number[j];
				a = chicken[c].x; // 치킨집의 a
				b = chicken[c].y; // 치킨집의 b
				dis = abs(home[i].x - a) + abs(home[i].y - b);
				mins = min(mins, dis);
			}
			homechicken += mins;
			mins = 100001;
		}
	
		distanceanswer = min(distanceanswer, homechicken);
		return;
	}
	for (int i = a; i < chicken.size(); i++)
	{
		if (visited[i]) continue;
		if (chicken.size() - i < M - a) return;
		visited[i] = true;
		number[a] = i;
		choice(a + 1, number);
		visited[i] = false;
	}

}


int main()
{
	cin >> N >> M;
	vector <int> answer(MAX);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int x;
			cin >> x;
			if (x == 1) {
				home.push_back({ i,j });
			}
			if (x == 2)
			{
				chicken.push_back({i,j});
			}
		}
	}

	choice(0, answer);


	cout << distanceanswer;

	return 0;


}