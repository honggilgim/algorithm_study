#include <iostream>
#include <queue>
#include <algorithm>
#define MAX 100001

using namespace std;

int N, K;
bool visited[MAX];
int minv = MAX;
queue<int> q;
int cot;
int maxv;



void bfs(int a) {
    maxv = max(N, K);
    q.push(a);
    visited[a] = true;
    while (!q.empty())
    {
        a = q.front();
        q.pop();
        if (a >= 0 && a <= maxv)
        {
            if (a == K)
            {
                if (cot < minv)
                    minv = cot;
            }
            if (visited[(a + 1)] == false)
            {
                q.push(a + 1);
                visited[(a + 1)] = true;
                cot++;
            }
            if (visited[(a - 1)] == false)
            {
                q.push(a - 1);
                visited[(a - 1)] = true;
                cot++;
            }
            if (visited[(2 * a)] == false)
            {
                q.push((2 * a));
                visited[(a - 2)] = true;
                cot++;
            }
        }
    }

}


int main()
{

    cin >> N >> K;
    bfs(N);

    cout << minv;

}
