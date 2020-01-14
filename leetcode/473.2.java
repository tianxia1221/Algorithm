class Solution {

    class cmp implements Comparator<Integer>{
        @Override //可以去掉。作用是检查下面的方法名是不是父类中所有的
        public int compare(Integer a,Integer b){
//        两种都可以，升序排序的话反过来就行
//        return a-b<0?1:-1;
            return b-a;
        }
    }

    public boolean makesquare(int[] nums) {
        if(0==nums.length) return false;

        int[] bucket = new int[4];
        int sum = 0;
        Arrays.sort(nums);
        for(int i: nums) sum += i;
        if(sum%4 != 0) return false;

        return makesquare(nums, nums.length-1, sum/4, bucket);
    }

    boolean makesquare(int[] nums, int i, int target, int[] bucket){
        if(i == -1) {
            if(bucket[0] == target && bucket[1] == target &&
                    bucket[2] == target && bucket[3] == target) return true;
        }

        for(int j=0; j<4; j++) {
            if(bucket[j] + nums[i] > target) continue;

            //put
            bucket[j] += nums[i];
            if(makesquare(nums, i-1, target, bucket)) return true;
            bucket[j] -= nums[i];
        }
        return false;
    }
}