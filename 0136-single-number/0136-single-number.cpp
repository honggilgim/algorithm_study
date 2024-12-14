class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int answer = 0;
        for (int num : nums) {
            //XOR 연산
            answer ^= num;
        }
        return answer;
    }
};