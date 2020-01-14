class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		if (0 == nums.size()) return 0;

		vector<int> largeSum(nums.size(), 0);
		largeSum[0] = nums[0];
		int ret = largeSum[0];

		for (int i = 1; i < nums.size(); i++) {
			largeSum[i] = max(largeSum[i - 1] + nums[i], nums[i]);
			ret = max(ret, largeSum[i]);
		}

		return ret;
	}
};

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int cur = nums[0];
		int ret = nums[0];
		for (int i = 1; i < nums.size(); i++) {
			cur = max(cur + nums[i], nums[i]);
			ret = max(cur, ret);
		}

		return ret;
	}
};