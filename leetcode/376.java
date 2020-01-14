class Solution {
    private enum STATE {
        BEGIN,
        UP,
        DOWN,
    }

    public int wiggleMaxLength(int[] nums) {
        int count = 1;
        STATE state = STATE.BEGIN;
        if (nums.length < 2) return nums.length;
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] == nums[i - 1]) continue;
            switch (state) {
                case BEGIN:
                    if (nums[i] > nums[i - 1]) state = STATE.UP;
                    else state = STATE.DOWN;
                    // (nums[i] > nums[i-1] ) ? state = STATE.UP : state = STATE.DOWN;
                    count++;
                    break;
                case UP:
                    if (nums[i] < nums[i - 1]) {
                        state = STATE.DOWN;
                        count++;
                    }
                    break;
                case DOWN:
                    if (nums[i] > nums[i - 1]) {
                        state = STATE.UP;
                        count++;
                    }
                    break;
            }
        }
        return count;
    }
}