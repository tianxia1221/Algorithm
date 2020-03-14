//Runtime: 21 ms, faster than 34.68% of Java online submissions for Range Sum Query - Mutable.
//        Memory Usage: 48 MB, less than 81.25% of Java online submissions for Range Sum Query - Mutable.
class NumArray {
    private int[] val;
    private int count;

    public NumArray(int[] nums) {
        if (nums.length == 0) return;
        count = nums.length;
        int size = highOne(count);
        val = new int[size];
        build_segment_tree(nums, 0, nums.length - 1,  0);
    }


    int highOne(int n) {
        int ret = n;
        // while(n){
        //     ret = n;
        //     n = n & (n -1);
        // }
        return ret << 2;
    }

    public void update(int i, int val) {
        update(i, val, 0, 0, count - 1);
    }


    void update(int i, int value, int pos, int left, int right) {

        if(left == right) {
            val[pos] = value;
            return;
        }

        int mid = left + (right -left)/2;
        int childLeftPos = 2 * pos + 1;
        int childRightPos = 2 * pos + 2;
        if(i > mid) update(i, value, childRightPos, mid+1, right);
        else update(i, value, childLeftPos, left, mid);
        val[pos] = val[childLeftPos] + val[childRightPos];
    }

    int sumRange(int i, int j) {
        return sumRange(i, j, 0, 0, count - 1);
    }

    int sumRange(int start, int end, int pos, int left, int right) {


        if(start<=left) start = left;
        if(end>=right) end = right;

        if(start==left && end ==right) return val[pos];

        int mid = left + (right - left)/2;
        int childLeftPos = 2 * pos + 1;
        int childRightPos = 2 * pos + 2;

        if(end <= mid)  return sumRange(start, end,childLeftPos, left, mid);
        else if(start > mid) return sumRange(start, end, childRightPos, mid + 1, right);

        return  sumRange(start, end, childLeftPos, left, mid) + sumRange(start, end, childRightPos, mid + 1, right);
    }

    void build_segment_tree(int[] nums, int left, int right, int pos) {
        if (left == right) {
            val[pos] = nums[left];
            return;
        }
        int mid = left + (right - left) / 2;
        int childLeftPos = 2 * pos + 1;
        int childRightPos = 2 * pos + 2;
        build_segment_tree(nums, left, mid, childLeftPos);
        build_segment_tree(nums, mid + 1, right, childRightPos);
        val[pos] = val[childLeftPos] + val[childRightPos];
    }
}

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */