class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, INT_MAX);
        dp[0] = 0;
        int pre;
        for(auto c: coins) {
            for(int i= c; i<=amount; i++) {
                pre = i - c;
                if(dp[pre] != INT_MAX) {
                    dp[i] = min(dp[i], dp[pre] + 1);
                }
            }
        }

        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};