#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
#define MAX 51

string board[MAX];

string w[8] =
{
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW"
};

string b[8] =
{
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB"
};

int wc(int a, int b)
{
    int cot = 0;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (board[a + i][b + j] != w[i][j])
                cot++;
        }
    }
    return cot;
}

int bc(int a, int k)
{
    int cot = 0;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (board[a + i][k + j] != b[i][j])
                cot++;
        }
    }
    return cot;
}

int main() {
    int N, M;
    int ans = 100011;
    int res;
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        cin >> board[i];
    }

    for (int i = 0; i <= (N - 8); i++)
    {
        for (int j = 0; j <= (M - 8); j++)
        {
            res = min(wc(i,j),bc(i,j));
            ans = min(ans,res);
        }
    }

    cout << ans << "\n";

    return 0;
}