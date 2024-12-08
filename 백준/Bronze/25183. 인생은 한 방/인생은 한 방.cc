#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#define endl "\n"

using namespace std;

int main() {
    int N;
    cin >> N;
    string temp;
    cin >> temp;
    
    bool answer = false;
    int answerValue=0;
    for(int i=0; i<N; i++) {
        if(i+1 <= N) {
            if(temp[i] == 'Z') {
                if(temp[i+1] == 'Y')
                    answerValue++;
                else
                    answerValue = 0;
            }
            else if((temp[i] - 'A') - (temp[i+1]-'A') == 1 ||
                    (temp[i] - 'A') - (temp[i+1]-'A') == -1)
                answerValue++;
            else
                answerValue=0;
            if(answerValue == 4) {
                answer = true;
                break;
            }
        }
    }
    
    if(answer)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
        
}
