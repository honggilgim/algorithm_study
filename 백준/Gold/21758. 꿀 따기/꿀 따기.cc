#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <math.h>
#define MAX 100001

#define endl "\n"

using namespace std;

int main() {
    int N;
    cin >> N;
    int arr[MAX] = {0,};
    int sum[MAX] = {0,};
    
    for(int i=0; i<N;i++) {
        int temp;
        cin >> temp;
        arr[i] = temp;
        if(i > 0)
            sum[i] = sum[i-1] + temp;
        else
            sum[i] = temp;
    }
    
    int answer = 0;
    
    // 벌1, 벌2, 벌통
    for(int i=1; i<N-1; i++) {
        int temp_answer;
        temp_answer = (sum[N-1] - arr[0] - arr[i]) + (sum[N-1] - sum[i]);
        //cout << "1 " << endl << endl;
        //cout << "i : " << i << endl;
        //cout << "(sum[N-1] - arr[0] - arr[i]) : " << (sum[N-1] - arr[0] - arr[i]) << endl;
        //cout << "(sum[N-1] - sum[i]) : " << (sum[N-1] - sum[i]) << endl;
        //cout << "temp_answer : " << temp_answer << endl;
        answer = max(answer,temp_answer);
    }
    
    // 벌1 벌통 벌2
    for(int i=1; i<N-1; i++) {
        int temp_answer;
        temp_answer = (sum[i] - arr[0]) + (sum[N-1] - sum[i-1] - arr[N-1]);
        //cout << "2 " << endl << endl;
        //cout << "i : " << i << endl;
        //cout << "(sum[i] - arr[0]) : " << (sum[i] - arr[0]) << endl;
        //cout << "(sum[N-1] - sum[i] - arr[N-1]) : " << (sum[N-1] - sum[i] - arr[N-1]) << endl;
        //cout << "temp_answer : " << temp_answer << endl;
        answer = max(answer,temp_answer);
    }
    
    // 벌통 벌1 벌2
    for(int i=1; i<N-1; i++) {
        int temp_answer;
        temp_answer = (sum[i-1]) + (sum[N-2] - arr[i]);
        //cout << "3 " << endl << endl;
        //cout << "i : " << i << endl;
        //cout << "(sum[i-1]) : " << (sum[i-1]) << endl;
        //cout << "(sum[N-1] - arr[i]) : " << (sum[N-1] - arr[i]) << endl;
        //cout << "temp_answer : " << temp_answer << endl;
        answer = max(answer,temp_answer);
    }
    
    cout << answer;
    
    return 0;
    
    
}
