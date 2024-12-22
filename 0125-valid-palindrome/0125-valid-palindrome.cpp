class Solution {
public:
    bool isPalindrome(string s) {
        string change_s;
        for(auto temp : s) {
            if('A' <= temp && temp <= 'Z') {
              temp += 32;
              change_s += temp;
            } else if ('a' <= temp && temp <= 'z')
                change_s += temp;
            else if (isdigit(temp) > 0)
                change_s += temp;
        }
        //if(change_s.size() == 1) return false;
        return equal(change_s.begin(), change_s.begin() + change_s.size()/2, change_s.rbegin());
    }
};