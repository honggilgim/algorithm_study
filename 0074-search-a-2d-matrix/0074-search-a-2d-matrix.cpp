class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rowCount = matrix.size();
        int colCount = matrix[0].size();
        

        int low = 0, high = rowCount - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (matrix[mid][0] <= target && (mid == rowCount - 1 || matrix[mid + 1][0] > target)) {
                low = mid;
                break;
            } else if (matrix[mid][0] > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        int row = low;
        if (row < 0 || row >= rowCount) return false;
        
        low = 0, high = colCount - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (matrix[row][mid] == target) return true;
            else if (matrix[row][mid] < target) low = mid + 1;
            else high = mid - 1;
        }

        return false; 
    }
};