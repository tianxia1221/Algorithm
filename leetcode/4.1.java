class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int n1 = nums1.length;
        int n2 = nums2.length;
        if (n1 > n2) return findMedianSortedArrays(nums2, nums1);

        int n = (n1 + n2 + 1) / 2;
        int low = 0, high = n1;
        int i, j;
        int isEven = (n1 + n2) % 2;

        int max1, max2, min1, min2;
        while (low <= high) {
            i = low + (high - low) / 2;
            j = n - i;

            min1 = i == 0 ? Integer.MIN_VALUE : nums1[i - 1];
            min2 = j == 0 ? Integer.MIN_VALUE : nums2[j - 1];

            max1 = i == n1 ? Integer.MAX_VALUE : nums1[i];
            max2 = j == n2 ? Integer.MAX_VALUE : nums2[j];

            if (max1 >= min2 && max2 >= min1) {
                if (isEven == 0) {
                    return (double) (Math.max(min1, min2) + Math.min(max1, max2)) / 2;
                } else {
                    return Math.max(min1, min2);
                }
            } else if (min1 > max2) {
                high = i - 1;
            } else {
                low = i + 1;
            }
        }

        return 0;
    }

}