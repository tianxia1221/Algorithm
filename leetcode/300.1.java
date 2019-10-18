class Solution {
    public int lengthOfLIS(int[] nums) {
        int ret = 0;
        int size = nums.length;
        int[] dp = new int[size];
        if(size == 0) return 0;
        dp[0] = 1;
        int preMax;
        for (int i = 0; i < size; i++) {
            dp[i] = 1;
            preMax = Integer.MIN_VALUE;
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j] && dp[j] > preMax) {
                    preMax = dp[j];
                    dp[i] = preMax + 1;
                }
            }
        }

        for (int i : dp)  ret = Integer.max(i, ret);
        return ret;
    }
}
