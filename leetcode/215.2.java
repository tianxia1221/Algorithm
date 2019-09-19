class Solution {
    public int findKthLargest(int[] nums, int k) {
        return findKthLargestRange(nums, 0, nums.length - 1, k);
    }

    public int findKthLargestRange(int[] nums, int start, int end, int k) {
        int pivot = (int) (Math.random()) % (end - start + 1) + start;
        int low = start;
        int high = end;
        int tmp = 0;
        System.out.println("pivot:" + pivot);
        //swap low and piovt
        tmp = nums[low];
        nums[low] = nums[pivot];
        nums[pivot] = tmp;
        low++;

        while (low <= high) {
            if (nums[low] < nums[start]) {
                tmp = nums[low];
                nums[low] = nums[high];
                nums[high] = tmp;
                high--;
            } else {
                low++;
            }
        }

        tmp = nums[high];
        nums[high] = nums[start];
        nums[start] = tmp;

        int count = high - start + 1;
        if (k == count) return nums[high];
        if (k > count) return findKthLargestRange(nums, high + 1, end, k - count);
        return findKthLargestRange(nums, start, high - 1, k);
    }

}