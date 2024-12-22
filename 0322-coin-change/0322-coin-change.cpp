class Solution {
public:

    int coinChange(vector<int>& coins, int amount) {
        int dp[10001];
        sort(coins.begin(),coins.end());
        for(int i=1; i<=amount; i++) {
            dp[i] = 2147483640;
            for(int j=0; j<coins.size();j++) {
                if((i-coins[j]) < 0) continue;
                dp[i] = min(dp[i],(dp[i-coins[j]]+1));
            }
        }
        return dp[amount] == 2147483640 ? -1 : dp[amount];
    }
};