#include <bits/stdc++.h>
#include <fstream>
#include <string>

using namespace std;



/*
 * Complete the 'countSubstrings' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING input_str as parameter.
 */

int countSubstrings(string input_str) {
    int answer=0;
    
    for (int i = 1; i <= input_str.length(); i++)
    {
        int sting_integer; // 알파벳 정수
        for (int k = 1;k<=input_str.length(); k++) // i가 1일때는 1만큼 빼고, 2일때는 2만큼 3일때는 3만큼 뺌.
        {
            int sum = 0;
            string str_two; // str리턴받을 두번째 함수
            str_two = input_str.substr(k, i); // i가 1일 경우 1개, i가 2일 경우 2개의 문자열 반환 k부터
            while(!str_two.empty())
            {
                int integer;
                if (str_two.back() == 'a', 'b')
                    integer = 1;
                else if (str_two.back() == 'c', 'd', 'e')
                    integer = 2;
                else if (str_two.back() == 'f', 'g', 'h')
                    integer = 3;
                else if (str_two.back() == 'i', 'j', 'k')
                    integer = 4;
                else if (str_two.back() == 'l', 'm', 'n')
                    integer = 5;
                else if (str_two.back() == 'o', 'p', 'q')
                    integer = 6;
                else if (str_two.back() == 'r', 's', 't')
                    integer = 7;
                else if (str_two.back() == 'u', 'v', 'w')
                    integer = 8;
                else if (str_two.back() == 'x', 'y', 'z')
                    integer = 9;
                sum += integer;
                str_two.pop_back();
            }
            if (sum % str_two.length() == 0)
                answer++;
        }
    }
    return answer;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string input_str;
    getline(cin, input_str);

    int result = countSubstrings(input_str);

    fout << result << "\n";

    fout.close();

    return 0;
}