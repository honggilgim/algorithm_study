class Solution {
public:
    int rob(vector<int>& nums) {
        int arr[101] = {0};
        arr[0] = nums[0];
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 0) return 0; 
        arr[1] = max(arr[0],nums[1]);
        for(int i=2; i<nums.size(); i++) {
            arr[i] = max(nums[i]+arr[i-2],arr[i-1]);
        }
        return arr[nums.size()-1];
    }
};