#include <string>
#include <vector>
#include <cstdlib>
#include <iostream>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int right = 12; // 12 : #
    int left = 10; // 10 : *
    for (int i = 0; i < numbers.size(); i++)
    {
        if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7)
        {
            answer += "L";
            left = numbers[i];
        }
        else if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9)
        {
            answer += "R";
            right = numbers[i];
        }
        else {
            if (numbers[i] == 0) // 0 : 11
                numbers[i] = 11;
            int LD = (abs(left - numbers[i]) / 3) + (abs(left - numbers[i]) % 3); // 손가락 위치 - 숫자패드 /3 : 같은 행인가 다른 행인가, 손가락 위치 - 숫자패드 % 3 : 같은 열인가 다른 열인가
            int RD = (abs(right - numbers[i]) / 3) + (abs(right - numbers[i]) % 3);
            //cout << "L : "<< LD << "\n";
            //cout <<"R : "<< RD << "\n";
            if (LD == RD)
            {
                if (hand == "right")
                {
                    answer += "R";
                    right = numbers[i];
                }
                else
                {
                    answer += "L";
                    left = numbers[i];
                }
            }
            else if (LD < RD)
            {
                answer += "L";
                left = numbers[i];
            }
            else
            {
                answer += "R";
                right = numbers[i];
            }
        }
    }
    return answer;
}