class Solution {
public:

    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};

    bool exist(vector<vector<char>>& board, string word) {
        bool check[11][11];
        for(int i=0; i<board.size(); i++) {
            for(int j=0; j<board[0].size(); j++) {
                if(findAns(board,word,i,j,0,check)) return true;
            }
        }
        return false;
    }

private:
    bool findAns(vector<vector<char>>& board, string target, int x, int y,
    int z, bool check[11][11]) {
        if(z == target.size()) {
            return true;
        }
        if (x < 0 || y < 0 || x >= board.size() || y >= board[0].size() || 
            board[x][y] != target[z] || check[x][y] == true) {
            return false;
        }
        check[x][y] = true;
        bool ret = findAns(board, target, x+dx[0], y+dy[0], z+1, check) ||
                findAns(board, target, x+dx[1], y+dy[1], z+1, check) ||
                findAns(board, target, x+dx[2], y+dy[2], z+1, check) ||
                findAns(board, target, x+dx[3], y+dy[3], z+1, check);
        check[x][y] = false;
        return ret;
    }
};