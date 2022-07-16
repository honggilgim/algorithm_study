#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> solution(vector<string> record) {
    map<string, string> user; // key type, value type
    string token;
    string result[5];
    vector<string> answer;
    int index = 0;
    for (int i = 0; i < record.size(); i++) {
        stringstream ss(record[i]);
        while (ss >> token)
        {
            result[index++] = token;
        }

        if (result[0] == "Leave")
        {
            index = 0;
            continue;
        }

        if (user.find(result[1]) != user.end())
        {
            user[result[1]] = result[2];
        }
        else
        {
            user.insert({ result[1],result[2] });
        }
        index = 0;
    }

    for (int i = 0; i < record.size(); i++) {
        stringstream ss(record[i]);
        while (ss >> token)
        {
            result[index++] = token;
        }

        if (result[0] == "Enter")
        {
            string ans;
            ans = user.at(result[1]) + "님이 들어왔습니다.";
            answer.push_back(ans);
        }
        else if (result[0] == "Leave")
        {
            string ans;
            ans = user.at(result[1]) + "님이 나갔습니다.";
            answer.push_back(ans);
        }
        index = 0;
    }
    return answer;
}