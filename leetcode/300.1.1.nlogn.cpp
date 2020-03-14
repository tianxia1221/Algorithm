class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		int ret = 0;
		int n = nums.size();
		vector<int> dp;
		int prePos;

		if (n < 2) return n;
		dp.push_back(nums[0]);

		for (int i = 1; i < n; i++) {
            if (nums[i] == dp.back()) continue;
			if (nums[i] > dp.back()) dp.push_back(nums[i]);
			else {
				prePos = binarySearch(dp, nums[i]);
				if (prePos < 0) {
					dp[-prePos - 1] = nums[i];
				}
			}
		}

		return dp.size();
	}

	int binarySearch(vector<int>& nums, int target) {
		int ret = 0;
		int left = 0;
		int right = nums.size() - 1;
		int mid;
		while (left <= right) {
			mid = left + (right - left) / 2;
			if (target == nums[mid]) return mid;
			else if (target > nums[mid]) {
				if (mid == nums.size() - 1 || target < nums[mid + 1]) {
					return -(mid + 1) - 1;
				}
				left = mid + 1;
			}
			//target < nums[mid]
			else {
				if (mid == 0 || target > nums[mid - 1]) {
					return -mid - 1;
				}
				right = mid - 1;
			}
		}

		return 1;
	}

//     binarySearch return value is as same as Java binarySearch
//      * @return index of the search key, if it is contained in the array
//      *         within the specified range;
//      *         otherwise, <tt>(-(<i>insertion point</i>) - 1)</tt>.  The
//      *         <i>insertion point</i> is defined as the point at which the
//      *         key would be inserted into the array: the index of the first
//      *         element in the range greater than the key,
//      *         or <tt>toIndex</tt> if all
//      *         elements in the range are less than the specified key.  Note
//      *         that this guarantees that the return value will be &gt;= 0 if
//      *         and only if the key is found.

};
