#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

int main() {
	int N;
	// 양수 음수 곱하기
	// 0나왔을때는 가장 작은 음수랑 곱하기
	// 1은 곱하지 않기
	vector<int> plus;
	vector<int> minus;
	int zerocount = 0;
	vector<int> sum;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		if (temp > 0) {
			if (temp == 1) {
				sum.push_back(temp);
			}
			else {
				plus.push_back(temp);
			}
		}
		else if (temp < 0) {
			minus.push_back(temp);
		}
		else {
			zerocount++;
		}
	}

	sort(plus.begin(), plus.end());
	sort(minus.begin(), minus.end());
	if (plus.size() % 2 != 0)
		sum.push_back(plus[0]);

	for (int i = (plus.size()-1); i > 0;i-=2)
	{
		sum.push_back((plus[i] * plus[i - 1]));
	}

	if ((minus.size() % 2) != 0)
	{
		if (zerocount > 0)
			minus.pop_back();
		sum.push_back(minus[minus.size() - 1]);
	}



	for (int i = 0;i < (minus.size()-1);i -= 2)
	{
		sum.push_back((minus[i] * minus[i - 1]));
	}

	int ans = 0;
	for (int i = 0; i < sum.size(); i++)
		ans += sum[i];
	cout << ans;
	return 0;
}