class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> subnums;
        vector<vector<int>> answer;
        sort(candidates.begin(),candidates.end());
        findAns(0,answer,candidates,subnums,target);
        return answer;
    }

private :
    void findAns (int index,vector<vector<int>>& answer,vector<int>& nums,vector<int>& subnums,int target) {
        if(target == 0) {
            answer.push_back(subnums);
            return;
        }
        if(target < 0 || index == nums.size())
            return;

        for(int k=index; k<nums.size(); k++) {
            if (k > index && nums[k] == nums[k - 1]) continue;
            if(nums[k] > target) break;
            subnums.push_back(nums[k]);
            findAns(k+1,answer,nums,subnums,target-nums[k]);
            subnums.pop_back();
        }
    }
};