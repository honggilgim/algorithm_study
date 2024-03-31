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
    
    int N,M;
    cin >> N;
    
    vector <int> crain;
    
    for(int i=0; i<N; i++) {
        int temp;
        cin >> temp;
        crain.push_back(temp);
    }
    
    cin >> M;
    
    vector<int> box;
    
    for(int i=0; i<M; i++) {
        int temp;
        cin >> temp;
        box.push_back(temp);
    }
    
    sort(crain.begin(),crain.end(),greater<int>());
    sort(box.begin(),box.end(),greater<int>());
    
    int answer=0;
    
    if(box[0] > crain[0])
        answer = -1;
    else {
        while(!box.empty()) {
            for(int i=0; i<crain.size(); i++) {
                for(int j=0; j<box.size(); j++) {
                    if(crain[i] >= box[j]) {
                        box.erase(box.begin() + j);
                        break;
                    }
                }
            }
            
            answer++;
        }
    }
    
    cout << answer;
    
    return 0;
}
