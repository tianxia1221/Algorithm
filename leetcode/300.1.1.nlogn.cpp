class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		int ret = 0;
		int size = nums.size();
		vector<int> dp;
		int last;
		int pos;

		if (size < 2) return size;
		dp.push_back(nums[0]);

		for (int i = 1; i < size; i++) {
			last = dp[dp.size() - 1];

			if (nums[i] == last) continue;

			if (nums[i] > last) dp.push_back(nums[i]);
			else {
				pos = binarySearch(dp, nums[i]);
				if (pos < 0) {
					dp[-pos - 1] = nums[i];
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
					return -(mid)-1;
				}
				right = mid - 1;
			}
		}

		return 1;
	}
};
