class Solution {
public:
	int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, 0);
		int pre;

		sort(coins.begin(), coins.end());
		for (int i = 1; i <= amount; i++) {
			dp[i] = -1;
			for (int j = 0; j < coins.size(); j++) {
				pre = i - coins[j];
                if(pre < 0) break;
                if(-1 != dp[pre])
				    dp[i] == -1 ? dp[i] = dp[pre] + 1 : dp[i] = min(dp[i], dp[pre] + 1);
			}
		}
		return dp[amount];
	}
};