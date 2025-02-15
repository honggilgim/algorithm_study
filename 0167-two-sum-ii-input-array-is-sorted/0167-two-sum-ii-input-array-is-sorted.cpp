class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int a = numbers.size()-1;
        int b = 0;
        vector<int> answer;
        while(numbers[a] + numbers[b] != target) {
            if(numbers[a] + numbers[b] > target)
                a--;
            else if(numbers[a] + numbers[b] < target)
                b++;
        }
        answer.push_back(b+1);
        answer.push_back(a+1);
        return answer;
    }
};