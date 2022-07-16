#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int a = 0;
    int k = 0;
    for (int i = 0; i < lottos.size(); i++)
    {
        if (lottos[i] == 0)
            k++;
        for (int j = 0; j < win_nums.size(); j++)
        {
            if (lottos[i] == win_nums[j])
            {
                a++;
                win_nums.erase(win_nums.begin() + j);
            }
        }
    }

    int f, s;

    if (a < 2)
        s = 6;
    else
        s = 6 - a + 1;
    if (k + a < 2)
        f = 6;
    else
        f = 6 - (a + k) + 1;

    answer.push_back(f);
    answer.push_back(s);

    return answer;
}