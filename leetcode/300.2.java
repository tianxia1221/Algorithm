class Solution {
    public int lengthOfLIS(int[] nums) {
        int ret = 0;
        int size = nums.length;
        List<Integer> dp = new ArrayList<>();
        int last;

        if(size < 2) return size;
        dp.add(nums[0]);

        for (int i = 1; i < size; i++) {
            last = dp.get(dp.size()-1);

            if(nums[i] == last) continue;

            if(nums[i] > last) dp.add(nums[i]);
            else {
                for (int j = 0; j < dp.size(); j++){
                    if (nums[i] > dp.get(j) ) {
                        continue;
                    }
                    else if(nums[i] == dp.get(j) ){
                        break;
                    }
                    else{
                        dp.set(j , nums[i]);
                        break;
                    }
                }
            }
        }

        return dp.size();
    }
}

class Solution {
    public int lengthOfLIS(int[] nums) {
        int ret = 0;
        int size = nums.length;
        List<Integer> dp = new ArrayList<>();
        int last;

        if(size < 2) return size;
        dp.add(nums[0]);

        for (int i = 1; i < size; i++) {
            last = dp.get(dp.size()-1);
            if(nums[i] == last) continue;
            if(nums[i] > last) dp.add(nums[i]);
            else {
//                for (int j = 0; j < dp.size(); j++){
//                    if (nums[i] > dp.get(j) ) {
//                        continue;
//                    }
//                    else if(nums[i] == dp.get(j) ){
//                        break;
//                    }
//                    else{
//                        dp.set(j , nums[i]);
//                        break;
//                    }
//                }
                int pos = Collections.binarySearch(dp, nums[i]);
                if(pos < 0)
                    dp.set(-(pos + 1) , nums[i]);

            }
        }

        return dp.size();
    }
}
