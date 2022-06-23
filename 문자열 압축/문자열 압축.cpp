#include <string>
#include <iostream>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = s.size();
    // 최대 반복횟수는 문자열의 절반 길이만큼이다.
    for (int i = 1; i <= s.size() / 2; i++) {
        int cnt = 1;
        string temp = "", a = "";
        // 0부터 i까지의 문자열 a
        a = s.substr(0, i);
        for (int j = i; j < s.size(); j += i) {
            if (a == s.substr(j, i)) cnt++;
            else {
                // 카운트가 1보다 크면, cnt를 temp에 더해주고 a를 더해준다.
                if (cnt > 1) temp += to_string(cnt);
                temp += a;
                // a를 새로 비교하는 문자열로 치환해주고 cnt를 1로 만들어준다.
                a = s.substr(j, i);
                cnt = 1;
            }
        }
        //비교 후, 남는 문자열이 있을 때 cnt가 1보다 크면, cnt를 문자열로 저장해주고 남는 문자열을 그대로 더해준다.
        if (cnt > 1) temp += to_string(cnt);
        temp += a;
        //정답 비교
        if (answer > temp.size()) answer = temp.size();
        //cout << temp << endl;
    }
    return answer;
}