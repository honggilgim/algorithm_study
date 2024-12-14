class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int x = grid.size();
        int y = grid[0].size();

        bool visited[102][102] = {false};
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, -1, 0, 1};
        int answer = 0;

        for(int i =0; i<x; i++) {
            for(int j=0;j<y;j++) {
                if(grid[i][j] == '1' && visited[i][j] == false) {
                    answer++;
                    queue<pair<int, int>> q;
                    q.push({i, j});

                    while(!q.empty()){
                        int nx = q.front().first;
                        int ny = q.front().second;
                        q.pop();

                        for(int i = 0; i < 4; i++){
                            int nnx = nx + dx[i];
                            int nny = ny + dy[i];
                            if(((0 <= nny && nny < y) 
                            && (0 <= nnx && nnx < x)) 
                            && grid[nnx][nny] == '1'
                            && visited[nnx][nny] == false){
                                visited[nnx][nny] = true;
                                q.push({nnx, nny});
                            }
                        }
                    }
                        
                    }
                }

            }
        return answer;
    }
};