class Solution {
public:
    int search(vector<int>& nums, int target) {
        int x=0;
        int y= nums.size();

        while(x < y) {
            int mid = (x+y) /2;
            if(nums[mid] > target) y=mid;
            else x=mid+1;
        }
        x--;
        if(x >= 0 && nums[x] == target) return x;
        else return -1;
    }
};