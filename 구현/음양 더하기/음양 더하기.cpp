#include <string>
#include <vector>

using namespace std;

int solution(vector<int> absolutes, vector<bool> signs) {
    int answer = 0;
    int k = 0;
    for (int i = 0; i < absolutes.size(); i++)
    {
        if (signs[i] == true)
            k = absolutes[i];
        else
            k = -1 * absolutes[i];
        answer += k;
    }
    return answer;
}