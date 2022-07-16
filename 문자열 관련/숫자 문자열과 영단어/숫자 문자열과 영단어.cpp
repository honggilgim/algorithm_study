#include <string>
#include <vector>
#include <iostream>

using namespace std;

int check(string s) {
    if (s == "zero") {
        return 0;
    }
    else if (s == "one") {
        return 1;
    }
    else if (s == "two") {
        return 2;
    }
    else if (s == "three") {
        return 3;
    }
    else if (s == "four") {
        return 4;
    }
    else if (s == "five") {
        return 5;
    }
    else if (s == "six") {
        return 6;
    }
    else if (s == "seven") {
        return 7;
    }
    else if (s == "eight") {
        return 8;
    }
    else if (s == "nine") {
        return 9;
    }
    else {
        return 10;
    }
}

int solution(string s) {
    int answer = 0;
    string ss = "";
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            answer *= 10;
            answer += (s[i] - '0');
        }
        else
        {
            ss += s[i];
            int result = check(ss);
            if (result != 10)
            {
                answer *= 10;
                answer += result;
                ss = "";
                //cout << answer << "\n";
            }
        }

    }
    return answer;
}