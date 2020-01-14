class NumArray {
    int[] tree_nums;
    int[] format_nums;

    public NumArray(int[] nums) {
        tree_nums = new int[nums.length + 1];
        format_nums = new int[nums.length + 1];

        int j, count;
        for (int i = 1; i < nums.length + 1; i++) {
            format_nums[i] = nums[i - 1];
            tree_nums[i] = 0;
            count = lowestBit(i);
            for (j = 0; j < count; j++) {
                tree_nums[i] += nums[i - j - 1];
            }
        }
    }

    public void update(int i, int val) {
        update_node(i + 1, val - format_nums[i + 1]);
        format_nums[i + 1] = val;
    }

    public int sumRange(int i, int j) {
        return sum(j + 1) - sum(i);
    }

    int lowestBit(int n) {
        return n & (-n);
    }

    void update_node(int i, int val) {

        int count = tree_nums.length;
        while (i < count) {
            tree_nums[i] += val;
            i += lowestBit(i);
        }

    }

    int sum(int i) {
        int ret = 0;
        while (i > 0) {
            ret += tree_nums[i];
            i -= lowestBit(i);
        }
        return ret;
    }
}

