class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int x = 1;
        int y = 1000000001;
        int answer = y;
        while(x <= y) {
            int mid = (x+y) / 2;
            long long int target = 0;
            double temp;
            for(int ba : piles) {
                temp = (double)ba/mid;
                target += ceil(temp);
            }
            if(target <= h) {answer = mid; y = mid-1;}
            else x = mid+1;
        }
        return answer;
    }
};