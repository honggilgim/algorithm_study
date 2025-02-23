class Solution {
public:
    set<vector<int>> answer;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> subnums;
        sort(nums.begin(),nums.end());
        findAns(nums,0,subnums);
        return vector<vector<int>> (answer.begin(), answer.end());
    }

private:
    void findAns(vector<int>& nums,int i,
    vector<int>& subnums) {
        if(i>=nums.size()) {
            answer.insert(subnums);
            return;
        }

        subnums.push_back(nums[i]);
        findAns(nums, i+1, subnums);
        subnums.pop_back();
        findAns(nums, i+1, subnums);
    }
};