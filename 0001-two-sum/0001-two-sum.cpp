class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> answer;
        unordered_map<int,int> number;

        for(auto temp : nums) {
            number[temp]++;
        }
        int one,two = 0;
        for(auto temp : nums) {
            number[temp]--;
            if(number[target-temp] != 0) {
                one = temp;
                two = target-temp;
                break;
            }
            number[temp]++;
        }
        if(one == two) {
            one = find(nums.begin(), nums.end(), one) - nums.begin();
            nums.erase(nums.begin() + one);
            two = find(nums.begin(), nums.end(), two) - nums.begin()+1;
        } else {
            one = find(nums.begin(), nums.end(), one) - nums.begin();
            two = find(nums.begin(), nums.end(), two) - nums.begin();
        }
        answer.push_back(one);
        answer.push_back(two);
        return answer;
    }
};