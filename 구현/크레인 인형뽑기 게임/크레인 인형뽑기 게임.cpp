#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    vector<int> crain;
    int answer = 0;
    crain.push_back(-1);
    for (int i = 0; i < moves.size(); i++)
    {
        for (int k = 0; k < board.size(); k++)
        {
            if (board[k][(moves[i] - 1)] == 0)
                continue;
            else
            {
                if (crain.back() == board[k][(moves[i] - 1)])
                {
                    answer++;
                    crain.pop_back();
                    board[k][(moves[i] - 1)] = 0;
                    break;
                }
                else {
                    crain.push_back(board[k][(moves[i] - 1)]);
                    board[k][(moves[i] - 1)] = 0;
                    // for(int j=0; j<crain.size(); j++)
                    //     cout<<crain[j];
                    // cout << "\n";
                    break;
                }
            }
        }
    }
    answer *= 2;
    return answer;
}