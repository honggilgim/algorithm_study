#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include <cstring>

#define MAX 4001

using namespace std;

int dp[MAX][MAX] = {0};

int main() {
    // 입출력시간 조정
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string s1,s2;
    
    cin >> s1 >> s2;
    
    int answer=0;
    
    for(int i=0; i<s1.size(); i++) {
        for(int j=0; j<s2.size(); j++) {
            if(s1[i] == s2[j]) {
                dp[i][j] = 1;
                if(i > 0 && j > 0)
                    dp[i][j] += dp[i-1][j-1];
            }
            
            answer = max(answer,dp[i][j]);
        }
    }
    /*
    for(int i=0; i<=s1.size(); i++) {
        for(int j=0; j<=s2.size(); j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
     */
    
    cout << answer;
    
    return 0;
}
