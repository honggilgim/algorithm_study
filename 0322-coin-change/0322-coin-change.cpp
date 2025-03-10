class Solution {
public:

    int coinChange(vector<int>& coins, int amount) {
        int dp[10001];
        //sort(coins.begin(),coins.end());
        for(int i=1; i<=amount; i++) {
            dp[i] = 10001;
            for(int temp : coins) {
                if((i-temp) < 0) continue;
                dp[i] = min(dp[i],(dp[i-temp]+1));
            }
        }
        return dp[amount] == 10001 ? -1 : dp[amount];
    }
};