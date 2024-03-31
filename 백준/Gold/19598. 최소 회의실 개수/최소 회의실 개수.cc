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
    
    int N;
    cin >> N;
    vector<pair<int,int>> arr;
    for(int i=0; i<N; i++) {
        int temp1, temp2;
        cin >> temp1 >> temp2;
        arr.push_back({temp1,temp2});
    }
    
    sort(arr.begin(),arr.end());
    
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(arr[0].second);
    int answer = 0;
    for(int i=1; i<N; i++) {
        while(!pq.empty() && (pq.top() <= arr[i].first))
            pq.pop();
        pq.push(arr[i].second);
        answer = max(answer,(int)pq.size());
    }
    
    cout << answer;
    
    return 0;
}
