#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string, int> map;
    for (auto man : participant)
    {
        if (map.end() == map.find(man))
            map.insert(make_pair(man, 1));
        else
            map[man]++;
    }
    for (auto man : completion)
        map[man]--;

    for (auto man : participant)
    {
        if (map[man] > 0)
        {
            answer = man;
            break;
        }
    }
    return answer;
}