class Solution {
    public boolean makesquare(int[] nums) {
        if(0==nums.length) return false;

        int sum = 0;
        for(int i: nums) sum += i;
        if(sum%4 != 0) return false;

        int target = sum/4;

        int all = 1 << nums.length;
        List<Integer> oneSide = new ArrayList<>();
        List<Integer> twoSide = new ArrayList<>();

        int index = 0;
        for(int i=0; i<all; i++) {
            sum = 0;
            for(int j=0; j<nums.length; j++){

                if((i&(1<<j)) != 0){
                    // if((i>>j)&1){
                    sum += nums[j];
                }
                if(sum > target) break;
            }
            if(sum == target) {
                oneSide.add(i);
            }
        }

        for(int i=0; i<oneSide.size(); i++) {
            for(int j=0; j<oneSide.size(); j++) {
                if((oneSide.get(i) & oneSide.get(j)) == 0) {
                    twoSide.add(oneSide.get(i)| oneSide.get(j) );
                }
            }
        }

        for(int i=0; i<twoSide.size(); i++) {
            for(int j=0; j<twoSide.size(); j++)
                if((twoSide.get(i) & twoSide.get(j)) == 0) return true;
        }

        return false;
    }
}
