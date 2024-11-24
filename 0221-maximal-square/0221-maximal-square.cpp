class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {

        
        int m = matrix.size();
        int n = matrix[0].size();

        int dparr[301][301] = {0,};
        int answer = 0;

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(i == 0 || j == 0)
                    dparr[i][j] = matrix[i][j] - 48;
                else if (matrix[i][j] == '0') {
                    dparr[i][j] = 0;
                } else {
                    dparr[i][j] = min(dparr[i-1][j-1],min(dparr[i-1][j],dparr[i][j-1])) +1;
                }
                answer = max(answer,dparr[i][j]);
            }

        }

        return answer * answer;
    }
};