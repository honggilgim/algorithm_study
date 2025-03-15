class Solution {
public:
    static bool cmp(const pair<int, int>& a,const pair<int, int>& b){
        return a.second > b.second;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        for(int temp : nums)
            m[temp]++;
        vector<pair<int, int>> vec(m.begin(), m.end());
        sort(vec.begin(),vec.end(),cmp);
        vector<int> ans;
        for(int i=0; i<k; i++)
            ans.push_back(vec[i].first);

        return ans;
    }
};