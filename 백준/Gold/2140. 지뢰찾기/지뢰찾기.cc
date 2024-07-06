#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <math.h>
#define MAX 101

#define endl "\n"

using namespace std;

char arr[MAX][MAX];
void minusss(int i,int j) {
    if(arr[i][j] != '#') {
        int temp;
        temp = arr[i][j]-'0';
        if(temp != 0)
            temp--;
        arr[i][j] = temp+'0';
    }
}

int main() {
    
    int n;
    cin >> n;
    for(int i=0;i<n;i++) {
        string temp;
        cin >> temp;
        for(int j=0; j<temp.size(); j++)
            arr[i][j] = temp[j];
        
    }
    // 상하좌우 arr[i][j]
    int answer = 0;
    for(int i=1; i<n; i++) {
        for(int j=1; j<n; j++) {
            if(arr[i][j] != '#')
                continue;
            if(arr[i-1][j-1] == '0')
                continue;
            else if(arr[i][j-1] == '0')
                continue;
            else if((i+1) <= n &&arr[i+1][j-1] == '0')
                continue;
            else if(arr[i-1][j] == '0')
                continue;
            else if((i+1) <= n && arr[i+1][j] == '0')
                continue;
            else if((j+1) <= n && arr[i-1][j+1] == '0')
                continue;
            else if((j+1) <= n && arr[i][j+1] == '0')
                continue;
            else if((j+1) <= n && arr[i+1][j+1] == '0')
                continue;
            
            answer++;
            
            minusss(i-1,j-1);
            minusss(i,j-1);
            if((i+1) <= n) {
                minusss(i+1,j-1);
                minusss(i+1,j);
            }
            minusss(i-1,j);
            if((j+1) <= n) {
                minusss(i-1,j+1);
                minusss(i,j+1);
                minusss(i+1,j+1);
            }
        }
    }
    cout << answer;
    return 0;
}
