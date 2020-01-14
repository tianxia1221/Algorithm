//Runtime: 33 ms, faster than 57.58% of Java online submissions for 3Sum.
//        Memory Usage: 47.9 MB, less than 83.74% of Java online submissions for 3Sum.
class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();
        int cur, low, high, tmp;

        Arrays.sort(nums);
        int lastIndex = nums.length-1;
        for(int i=0; i< nums.length - 2; i++) {

            if(i>=1 && nums[i] == nums[i-1]) continue;

            cur = -nums[i];
            low = i+1;
            high = lastIndex;

            while(low < high) {
                tmp = nums[low] + nums[high];
                if(tmp == cur) {
                    res.add(Arrays.asList(nums[i], nums[low], nums[high]));
                    low++;
                    high--;
// OK also
//                     while(low<lastIndex && nums[low] == nums[low - 1])
//                         low++;
//                     while(high>0 && nums[high] == nums[high + 1])
//                         high--;

                    while(low<high && nums[low]==nums[low-1])
                        low++;

                    while(low<high  && nums[high]== nums[high + 1])
                        high--;
                }
                else if(tmp > cur) {
                    high--;
                }
                else{
                    low++;
                }
            }
        }
        return res;

    }
}