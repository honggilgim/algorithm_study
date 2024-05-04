#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <math.h>
#define MAX 10001
#define endl "\n"

using namespace std;

int main() {
    int N;
    cin >> N;
    priority_queue<int> pq;
    
    int dasam = 0;
    int answer = 0;
    
    for(int i=0; i<N; i++) {
        if(i == 0) {
            cin >> dasam;
            continue;
        }
        int temp;
        cin >> temp;
        pq.push(temp);
    }
    
    while(!pq.empty()) {
        int count = pq.top();
        pq.pop();
        //cout << "dasam : "<< dasam << "count : " << count << endl;
        if(dasam > count)
            break;
        pq.push(count-1);
        dasam++;
        answer++;
    }
    
    cout << answer;
    return 0;
}
