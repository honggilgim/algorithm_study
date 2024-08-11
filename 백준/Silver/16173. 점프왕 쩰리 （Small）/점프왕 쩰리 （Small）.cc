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

bool answer = false;



void dfs(int x,int y) {
        
    if(arr[x][y] == -1) {
        answer = true;
        return;
    }
    
    for(int i=0; i<2; i++) {
        int nx = x + dx[i] * arr[x][y];
        int ny = y + dy[i] * arr[x][y];
        
        if(nx < n && ny < n && visited[nx][ny] == false) {
            visited[nx][ny] = true;
            dfs(nx,ny);
            visited[nx][ny] = false;
        }
    }
}

int main() {
    
    cin >> n;
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> arr[i][j];
        }
    }
    
    dfs(0,0);
    if(answer)
        cout << "HaruHaru";
    else
        cout << "Hing";
    
    return 0;
}
