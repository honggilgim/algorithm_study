class Solution {
public:
    bool isAnagram(string s, string t) {

        if(s.length() != t.length())
            return false;

        unordered_map<char,int> s_map;
        unordered_map<char,int> t_map;

        for (auto temp : s) {
            s_map[temp]++;
        }
        for (auto temp : t) {
            t_map[temp]++;
        }

        for (auto temp : s_map) {
            if (temp.second != t_map[temp.first]) {
                return false;
            }
        }
        return true;


        /*
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        if(s == t)
            return true;
        else
            return false;
            */



        /*if(s.length() != t.length())
            return false;
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        for(int i=0; i<s.length(); i++) {
            if(s[i] != t[i])
                return false;
        }
        return true;
        */



    }
};