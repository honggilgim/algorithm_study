class Solution {
public:
    bool canChange(string start, string target) {
        int a = 0, b = 0;
        int size = start.size();

        while(a < size || b < size) {
            while(start[a] == '_' && a<size) a++;
            while(target[b] == '_' && b<size) b++;

            if(start[a] != target[b]) return false;
            if(start[a] == 'L' && a < b) return false;
            if(start[a] == 'R' && a > b) return false;
            a++;
            b++;
        }
        return true;
    }
};