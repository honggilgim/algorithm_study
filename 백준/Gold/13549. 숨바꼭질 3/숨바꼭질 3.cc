#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include <cstring>

#define endl "\n"
#define MAX 1000001

using namespace std;

bool visited[MAX];

queue <pair<int,int>> q;
int answer;

int N,K;

int dx[2] = {-1,1};

void bfs() {
    
    q.push({N,0});

    while(!q.empty()) {
        int place = q.front().first;
        int time = q.front().second;
        q.pop();
        
        //cout << place << " ";
        
        if(place == K) {
            answer = time;
            return;
        }
        for(int i=0; i<3; i++) {
            
            int nx = place;
            
            if(i == 0)
                nx *=2;
            else
                nx += dx[(i-1)];
            
            if(nx > 100005 || nx < 0)
                continue;
            
            if(visited[nx] == false) {
                visited[nx] = true;
                if(i == 0)
                    q.push({nx,time});
                else
                    q.push({nx,time+1});
            }
        }
        
    }
}

int main() {
    // 입출력시간 조정
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> K;
    bfs();
    
    cout << answer;
    
    return 0;
}
