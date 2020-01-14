class Solution {
    public int coinChange(int[] coins, int amount) {
        int[] dp=new int[amount + 1];
        int pre;

        //	Arrays.sort(coins);

        for (int i = 1; i <= amount; i++) {
            dp[i] = -1;
            for (int j = 0; j < coins.length; j++) {
                pre = i - coins[j];

                if(pre < 0) continue;//break;

                if(-1 != dp[pre])
                    dp[i] = (dp[i] == -1) ? dp[pre] + 1 :Integer.min(dp[i], dp[pre] + 1);
            }
        }
        return dp[amount];
    }
}