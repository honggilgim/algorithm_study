#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include <cstring>

#define endl "\n"
#define MAX 100

using namespace std;

int main() {
    // 입출력시간 조정
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin >> N;
    map<string, int> dae;
    vector<string> zero;
    int answer = 0;

    for (int i = 0; i < N; ++i) {
        string temp;
        cin >> temp;
        dae[temp] = i;
    }

    for (int i = 0; i < N; ++i) {
        string temp;
        cin >> temp;
        zero.push_back(temp);
    }

    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            if (dae[zero[i]] > dae[zero[j]]) {
                answer++;
                break;
            }
        }
    }
    
    cout << answer << endl;
    
    return 0;
}
