class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> answer;
        sort(nums.begin(),nums.end());
        for(int i=0; i<nums.size(); i++) {
            for(int j =i+1; j<nums.size(); j++) {
                for(int z = j+1; z<nums.size(); z++) {
                    if(nums[i] + nums[j] + nums[z] == 0 )
                        answer.insert({nums[i],nums[j],nums[z]});
                }
            }
        }

        return vector<vector<int>>(answer.begin(),answer.end());
    }
};