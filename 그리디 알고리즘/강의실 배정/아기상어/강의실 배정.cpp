#include <iostream>
#include <stack>
#include <queue>
#include<algorithm>

using namespace std;

int main() {
	vector <pair<int,int>> time;
	priority_queue<int, vector<int>, greater<int>> pq; // 사용하는 클래스의 개수
	int N;
	cin >> N;
	int start, end;

	for (int i = 0; i < N; i++)
	{
		cin >> start >> end;
		time.push_back({ start,end });
	}

	sort(time.begin(),time.end());
	pq.push(time[0].second); // 교실 하나에서 수업 시작

	int count=1;
	for (int i = 1; i < N; i++)
	{
		if (pq.top() <= time[i].first) // 시작 시간보다 끝나는 시간이 작으면 교실 수업 변경
		{
			pq.pop();
			pq.push(time[i].second);
		}
		else { // 교실 추가
			pq.push(time[i].second);
		}
	}
	cout << pq.size();
	return 0;
	
}