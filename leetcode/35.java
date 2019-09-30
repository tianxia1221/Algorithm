class Solution {
    public int searchInsert(int[] nums, int target) {
        int left = 0;
        int right = nums.length - 1;
        int mid;
        while (right >= left) {
            // mid = left+(right-left)/2;
            mid = (left + right) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                if (mid == 0) return mid;
                if (target > nums[mid - 1]) return mid;

                right = mid - 1;

            } else if (nums[mid] < target) {
                if (mid == nums.length - 1) return mid + 1;
                if (target < nums[mid + 1]) return mid + 1;

                left = mid + 1;
            }
        }

        return 999;
    }
}


class Solution {
    public int searchInsert(int[] nums, int target) {
        int left = 0;
        int right = nums.length - 1;
        int mid;
        while (right >= left) {
            // mid = left+(right-left)/2;
            mid = (left + right) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                if (mid == 0 || target > nums[mid - 1]) return mid;
                right = mid - 1;

            } else if (nums[mid] < target) {
                if (mid == nums.length - 1 || (target < nums[mid + 1])) return mid + 1;
                left = mid + 1;
            }
        }
        return 999;
    }
}