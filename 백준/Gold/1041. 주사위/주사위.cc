#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <math.h>
#define endl "\n"

using namespace std;

int main() {
    
    long long int N;
    long long int answer=0;
    int number[6];
    int maxValue=0;
    cin >>N;
    for(int i=0; i<6; i++) {
        cin >> number[i];
    }
    
    if(N == 1) {
        for(auto i : number) {
            answer+=i;
            maxValue = max(i,maxValue);
        }
        answer -=maxValue;
    } else {
        number[0] = min(number[0],number[5]);
        number[1] = min(number[1],number[4]);
        number[2] = min(number[2],number[3]);
        
        sort(number, number+3);
        
        int tempValue1 = number[0];
        int tempValue2 = number[0] + number[1];
        int tempValue3 = number[0] + number[1] + number[2];
        
        // 3면
        answer += tempValue3 * 4;
        answer += tempValue2 * ((4 * (N-2)) + (4 * (N-1)));
        answer += tempValue1 * ((4 * (N-1) * (N-2)) + ((N-2) * (N-2)));
    }
    
    cout << answer;
    
    return 0;
}
