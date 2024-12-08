class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map <int,int> map;
        for(int a : nums) {
            if(map.find(a) == map.end()) map.insert({a,1});
            else return true;
        }
        return false;
    }
};