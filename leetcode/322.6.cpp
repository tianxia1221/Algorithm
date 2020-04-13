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



class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, INT_MAX);
        int pre;
        dp[0] = 0;
        for(int i=1; i<=amount; i++) {
            for(auto c: coins) {
                pre = i - c;
                if(pre < 0) continue;
                if(dp[pre] != INT_MAX)
                    dp[i] = min(dp[i], dp[pre] + 1);
            }
        }
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};