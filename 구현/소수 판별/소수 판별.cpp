#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> nums) {
    int sum = 0;
    int prime = 1;
    int answer = 0;
    for (int i = 0; i < nums.size(); i++) {
        for (int k = i + 1; k < nums.size(); k++) {
            for (int j = k + 1; j < nums.size(); j++) {
                sum = nums[i] + nums[k] + nums[j];
                //cout << sum << "   ";
                // 소수 판별 반복문 체 사용
                prime = 1;
                for (int a = 2; a <= sum / 2; a++)
                {
                    if (sum % a == 0) {
                        prime = 0;
                    }
                }
                if (prime == 1)
                    answer++;
            }
        }
    }
    return answer;
}