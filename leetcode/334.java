//Runtime: 4 ms, faster than 11.81% of Java online submissions for Increasing Triplet Subsequence.
//        Memory Usage: 38.7 MB, less than 95.35% of Java online submissions for Increasing Triplet Subsequence.
class Solution {
    public boolean increasingTriplet(int[] nums) {
        boolean res = false;
        if(nums.length < 1) return false;
        List<Integer> memo = new ArrayList<>();
        memo.add(nums[0]);
        int cur;
        for(int i=1; i<nums.length; i++) {
            if(memo.size() >= 3) break;
            if(nums[i] > memo.get(memo.size() - 1)){
                memo.add(nums[i]);
                continue;
            }
            for(int j=0; j<memo.size(); j++) {
                cur = memo.get(j);
                if(nums[i] <= cur) {
                    memo.set(j, nums[i]);
                    break;
                }
            }
        }
        return memo.size() >= 3;
    }
}