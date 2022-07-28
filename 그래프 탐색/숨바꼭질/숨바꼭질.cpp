#include <iostream>
#include <queue>
#include <algorithm>
#define MAX 100001

using namespace std;

int N, K;
bool visited[MAX];
queue<pair<int,int>> q;
int ans;
int maxv;



void bfs(int a,int b) {
    q.push(make_pair(a,b));
    visited[a] = true;
    while (!q.empty())
    {
        int a = q.front().first;
        int b = q.front().second;
        q.pop();
        if (a == K)
        {
            ans = b;
            break;
        }

        int a1 = a - 1;
        int a2 = a + 1;
        int a3 = a * 2;
        if (0 <= a1 && !visited[a1])
        {
            visited[a1] = true;
            q.push(make_pair(a1, b + 1));
        }
        if (a2 <= K && !visited[a2])
        {
            visited[a2] = true;
            q.push(make_pair(a2, b + 1));
        }
        if (a3 <= K+1 && !visited[a3])
        {
            visited[a3] = true;
            q.push(make_pair(a3, b + 1));
        }
    }

}


int main()
{

    cin >> N >> K;
    bfs(N,0);

    cout << ans;
    return 0;
}
