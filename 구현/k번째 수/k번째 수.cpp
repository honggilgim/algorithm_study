#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for (int i = 0; i < commands.size(); i++)
    {
        vector<int> arr;
        for (int k = (commands[i][0] - 1); k < commands[i][1]; k++)
        {
            arr.push_back(array[k]);
        }
        sort(arr.begin(), arr.end());
        answer.push_back(arr.at(commands[i][2] - 1));
    }
    return answer;
}