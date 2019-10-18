class Solution {
    public int maxSubArray(int[] nums) {
        if(0 == nums.length) return 0;

        int[] largeSum = new int[nums.length];
        largeSum[0] = nums[0];
        int ret = largeSum[0];

        for(int i=1; i<nums.length; i++) {
            largeSum[i]  = Integer.max(largeSum[i-1] + nums[i], nums[i]);
            ret = Integer.max(ret, largeSum[i]);
        }

        return ret;
    }
}
