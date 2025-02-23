class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int answer = INT_MIN;
        int Csum = 0;
        for(int i=0; i<nums.size(); i++) {
            Csum += nums[i];
            Csum = max(Csum,nums[i]);
            answer = max(answer,Csum);
        }
        return answer;
    }
};