class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 0) return 0; 

        int answerone,answertwo = 0;
        int temp = nums[nums.size()-1];
        nums[nums.size()-1] = 0;
        int arr[101] = {0};
        arr[0] = nums[0];
        arr[1] = max(arr[0],nums[1]);
        for(int i=2; i<nums.size(); i++) {
            arr[i] = max(nums[i]+arr[i-2],arr[i-1]);
        }
        answerone = arr[nums.size()-1];

        memset(arr,0,101*sizeof(int));
        nums[0] = 0;
        nums[nums.size()-1] = temp;

        arr[0] = nums[0];
        arr[1] = max(arr[0],nums[1]);
        for(int i=2; i<nums.size(); i++) {
            arr[i] = max(nums[i]+arr[i-2],arr[i-1]);
        }
        answertwo = arr[nums.size()-1];


        return max(answerone, answertwo);
    }
};