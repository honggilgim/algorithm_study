#include <iostream>
#include <string>
#include <algorithm>
#define endl "\n"

using namespace std;

int main() {
    string s;
    cin >> s;
    int arr[27] = {0};
    
    for(char a : s) {
        arr[a-'A']++;
    }
    
    int count=0;
    char answer = ' ';
    int alph2 = 0;
    for(int a : arr) {
        if(a%2!=0) {
            count++;
            answer = alph2 + 'A';
        }
        alph2++;
    }
    
    if(count > 1) {
        cout << "I'm Sorry Hansoo";
        return 0;
    }
    
    string firstanswer = "";
    string secondanswer = "";
    
    int alph = 0;
    for(int a : arr) {
        if(a > 0) {
            //cout << "A : " << a << endl;
            for(int j=0;j<(a/2);j++) {
                firstanswer += (alph + 'A');
            }
        }
        alph++;
    }
    
    secondanswer = firstanswer;
    reverse(secondanswer.begin(),secondanswer.end());
    string retrunvalue = "";
    if(answer != ' ')
        retrunvalue = firstanswer + answer + secondanswer;
    else
        retrunvalue = firstanswer + secondanswer;
    
    cout << retrunvalue << endl;
    
    return 0;
    
}
