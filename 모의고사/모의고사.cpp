#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector <int> one{ 1,2,3,4,5 };
    vector <int> two{ 2,1,2,3,2,4,2,5 };
    vector <int> three{ 3,3,1,1,2,2,4,4,5,5 };
    int count = 0;
    while (answers.size() > one.size())
    {
        if (count == 5)
            count = 0;
        one.push_back(one[count]);
        count++;
    }
    count = 0;
    while (answers.size() > two.size())
    {
        if (count == 8)
            count = 0;
        two.push_back(two[count]);
        count++;
    }
    while (answers.size() > three.size())
    {
        if (count == 10)
            count = 0;
        three.push_back(three[count]);
        count++;
    }
    int a, b, c = 0;
    for (int i = 0; i < answers.size(); i++)
    {
        if (answers[i] == one[i])
            a++;
        if (answers[i] == two[i])
            b++;
        if (answers[i] == three[i])
            c++;
    }
    if (a > b && a > c)
        answer.push_back(1);
    else if (b > a && b > c)
        answer.push_back(2);
    else if (c > a && c > b)
        answer.push_back(3);
    else if (a == b && b > c)
    {
        answer.push_back(1);
        answer.push_back(2);
    }
    else if (a == c && a > b)
    {
        answer.push_back(1);
        answer.push_back(3);
    }
    else if (b == c && b > a)
    {
        answer.push_back(2);
        answer.push_back(3);
    }
    else
    {
        answer.push_back(1);
        answer.push_back(2);
        answer.push_back(3);
    }
    return answer;
}