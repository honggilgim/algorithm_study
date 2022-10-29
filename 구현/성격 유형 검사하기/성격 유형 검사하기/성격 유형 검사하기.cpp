#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int arr[8];

int charnum(char s)
{

    if (s == 'R')
        return 0;
    else if (s == 'T')
        return 1;
    else if (s == 'F')
        return 2;
    else if (s == 'C')
        return 3;
    else if (s == 'M')
        return 4;
    else if (s == 'J')
        return 5;
    else if (s == 'A')
        return 6;
    else
        return 7;
}

void score(string s, int choice) {


    if (choice > 4)
    {
        int temp = charnum(s[1]);
        arr[temp] += (choice - 4);
        //cout << "위에 if 문 글자 : " << s[2] << "점수 : " << (choice-4) << "\n";
    }
    else if (choice < 4)
    {
        int temp = charnum(s[0]);
        arr[temp] += (4 - choice);
        //cout << "아래 if 문 글자 : " << s[1] << "점수 : " << (4 - choice) << "\n";
    }

}

string solution(vector<string> survey, vector<int> choices) {
    int size = survey.size();
    for (int i = 0; i < size; i++)
    {
        score(survey[i], choices[i]);
    }
    string answer = "";
    // for(int i=0; i<8; i++)
    //     cout << "  " << arr[i];

    if (arr[1] > arr[0])
        answer += "T";
    else
        answer += "R";

    if (arr[2] > arr[3])
        answer += "F";
    else
        answer += "C";

    if (arr[4] > arr[5])
        answer += "M";
    else
        answer += "J";

    if (arr[7] > arr[6])
        answer += "N";
    else
        answer += "A";
    return answer;
}