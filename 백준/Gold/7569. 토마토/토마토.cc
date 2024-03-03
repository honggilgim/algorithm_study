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

int arr[MAX][MAX][MAX];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int N,M,H;

struct tomato {
    int x;
    int y;
    int h;
};

queue<pair<tomato,int>> q;

int answer;



int main() {
    // 입출력시간 조정
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> M >> N >> H;
    
    for(int j=0; j<H; j++) { // 층 수
        for(int i=0; i< N; i++) { // 세로
            for(int k=0; k<M; k++) { // 가로
                int temp;
                cin >> temp;
                arr[k][i][j] = temp;
                if(arr[k][i][j] == 1)
                    q.push({{k,i,j},0});
            }
        }
    }
    
    if(q.size() == N*M*H) {
        cout << 0;
        return 0;
    }
    
    while(!q.empty()) {
        int x = q.front().first.x;
        int y = q.front().first.y;
        int h = q.front().first.h;
        
        int time = q.front().second;
        q.pop();
        answer = max(answer,time);
        
        for(int i=0; i<6; i++) {
            int nx = x;
            int ny = y;
            int nh = h;
            
            if(i < 4) {
                nx = x + dx[i];
                ny = y + dy[i];
            } else if( i == 4)
                nh += 1;
            else
                nh -= 1;
                    
            if(nx >= 0 && ny >=0 && nh >= 0 && nx < M && ny < N && nh < H && arr[nx][ny][nh] == 0) {
                arr[nx][ny][nh] = 1;
                q.push({{nx,ny,nh},time+1});
            }
        }
    }
    
    bool check = true;
    
    for(int j=0; j<H; j++) { // 층 수
        for(int i=0; i< N; i++) { // 세로
            for(int k=0; k<M; k++) { // 가로
                if(arr[k][i][j] == 0)
                    check = false;
            }
        }
    }
    
    if(check)
        cout << answer;
    else
        cout << -1;
    
    return 0;
}
