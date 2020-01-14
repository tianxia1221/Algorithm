class Solution {
    public int rob(int[] nums) {
        if(0 == nums.length) return 0;
        if(1 == nums.length) return nums[0];
        if(2 == nums.length) return Integer.max(nums[0],nums[1]);

        int prePre=nums[0];
        int pre = Integer.max(nums[0],nums[1]);
        int cur = 0;
        for(int i=2; i<nums.length; i++){
            cur = Integer.max(pre, prePre + nums[i]);
            prePre = pre;
            pre = cur;
        }
        return cur;
    }
}