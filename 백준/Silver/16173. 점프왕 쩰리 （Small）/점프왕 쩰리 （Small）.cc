#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <math.h>
#define MAX 4

#define endl "\n"

using namespace std;

// 100,000

int arr[MAX][MAX];
bool visited[MAX][MAX];
int n;

int dx[] = {1,0};
int dy[] = {0,1};



bool bfs(int x,int y) {
    queue<pair<int,int>> q;
    visited[x][y] = true;
    q.push({x,y});
    while(!q.empty()) {
        int ax = q.front().first;
        int ay = q.front().second;
        q.pop();
        
        if(arr[ax][ay] == -1)
            return true;
        
        for(int i=0; i<2; i++) {
            int nx = ax + dx[i] * arr[ax][ay];
            int ny = ay + dy[i] * arr[ax][ay];
            
            if(nx < n && ny < n && visited[nx][ny] == false) {
                visited[nx][ny] = true;
                q.push({nx,ny});
            }
        }
        
    }
    
    return false;
}

int main() {
    
    cin >> n;
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> arr[i][j];
        }
    }
    
    if(bfs(0,0))
        cout << "HaruHaru";
    else
        cout << "Hing";
    
    return 0;
}
