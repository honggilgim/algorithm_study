class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> answer;
        vector<int> subnums;
        sort(candidates.begin(),candidates.end());
        findAns(0,candidates,subnums,answer,target);
        return answer;
    }

private : void findAns (int index,
    vector<int>& nums,
    vector<int>& subnums, 
    vector<vector<int>>& answer,
    int target) {
        int sum = 0;
        for(int k : subnums)
            sum += k;
        if(sum == target) {
            answer.push_back(subnums);
        }
        if(sum > target)
            return;

        for(int k=index; k<nums.size(); k++) {
            subnums.push_back(nums[k]);
            findAns(k,nums,subnums,answer,target);
            subnums.pop_back();
        }
    }
};