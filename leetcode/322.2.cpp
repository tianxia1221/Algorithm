class Solution {

public:
	int coinChange(vector<int>& coins, int amount) {
		vector<int> dp(amount + 1, 0);
		return coinChange(coins, amount, dp);
	}

	int coinChange(vector<int>& coins, int amount, vector<int> &dp) {
		if (amount == 0) return 0;
		if (dp[amount] != 0) return dp[amount];
		dp[amount] = -1;
		for (auto c : coins) {
			if (amount - c < 0) continue;
			int curRes = coinChange(coins, amount - c, dp);
			if (curRes != -1)
				dp[amount] == -1 ? dp[amount] = curRes + 1 : dp[amount] = min(dp[amount], curRes + 1);
		}
		return dp[amount];
	}
};