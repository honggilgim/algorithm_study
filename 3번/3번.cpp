#include <bits/stdc++.h>

using namespace std;


int countSubstrings(string input_str) {
    int answer = 0;
    map<char, int>text;
    text['a'] = 1;
    text['b'] = 1;
    text['c'] = 2;
    text['d'] = 2;
    text['e'] = 2;
    text['f'] = 3;
    text['g'] = 3;
    text['h'] = 3;
    text['i'] = 4;
    text['j'] = 4;
    text['k'] = 4;
    text['l'] = 5;
    text['m'] = 5;
    text['n'] = 5;
    text['o'] = 6;
    text['p'] = 6;
    text['q'] = 6;
    text['r'] = 7;
    text['s'] = 7;
    text['t'] = 7;
    text['u'] = 8;
    text['v'] = 8;
    text['w'] = 8;
    text['x'] = 9;
    text['y'] = 9;
    text['z'] = 9;

    int length_charcter = input_str.length();
    for (int i = 0; i <= length_charcter; i++)
    {
        for (int k = 0; k <= length_charcter; k++) // i가 1일때는 1만큼 빼고, 2일때는 2만큼 3일때는 3만큼 뺌.
        {
            int sum = 0;
            string str_two; // str리턴받을 두번째 함수
            str_two = input_str.substr(k, i);
            int two_length = str_two.length();// i가 1일 경우 1개, i가 2일 경우 2개의 문자열 반환 k부터
            while (!str_two.empty())
            {
                char mes = str_two.back();
                int integer = 0;
                integer = text[mes];
                sum += integer;
                str_two.pop_back();
                cout << "integer" << integer << endl;;
                cout << "sum" << sum << endl;
                cout << "문자" << mes << endl;
            }
            cout << "sum" << sum << endl;
            cout << "길이" << two_length << endl;
            if (two_length!=0 && sum % two_length == 0)
                answer++;
        }
    }
    return answer-2;
}
int main()
{
   // ofstream fout(getenv("OUTPUT_PATH"));

    string input_str;
    getline(cin, input_str);

    int result = countSubstrings(input_str);

    //fout << result << "\n";

    //fout.close();

    return 0;
}


/*#include <iostream>
#include <map>

int main()
{
    std::map<std::string, int> test;

    test["first"] = 1;
    test["second"] = 2;
    test["third"] = 3;

    std::cout << test["first"] << std::endl;
    std::cout << test["second"] << std::endl;
    std::cout << test["third"] << std::endl;

    return 0;
}*/