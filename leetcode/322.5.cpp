class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, INT_MAX);
        sort(coins.begin(), coins.end(), greater<int>());
        return helper(coins, amount, dp);
    }

    int helper(vector<int>& coins, int amount, vector<int> &dp){

        if(dp[amount] != INT_MAX) return dp[amount];
        if(amount == 0) return dp[0] = 0;

        dp[amount] = -1;
        int tmp = 0;
        for(int i = 0; i<coins.size(); i++){
            tmp = amount-coins[i];
            if(tmp < 0 ) continue;
            helper(coins, tmp, dp);
            if(dp[tmp] != -1 && ( dp[amount] == -1 || dp[tmp]+1 < dp[amount])){
               dp[amount] = dp[tmp]+1 ;
            }
        }
        return dp[amount];
    }
};