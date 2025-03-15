class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        for(auto temp : strs) {
            string s = temp;
            sort(s.begin(),s.end());
            m[s].push_back(temp);
        }
        vector<vector<string>> ans;
        for(auto temp : m) {
            ans.push_back(temp.second);
        }
        return ans;
        
    }
};