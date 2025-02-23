class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> answer;
        vector<int> subnums;
        dfs(nums,0,subnums,answer);
        return answer;
    }

private:
    void dfs(vector<int>& nums,
    int i,
    vector<int>& subnums, 
    vector<vector<int>>& answer) {
        if(i>=nums.size()) {
            answer.push_back(subnums);
            return;
        }

        subnums.push_back(nums[i]);
        dfs(nums, i+1, subnums, answer);
        subnums.pop_back();
        dfs(nums, i+1, subnums, answer);
    }
};
