class Solution {
public:
	int rob(vector<int>& nums) {
		if (0 == nums.size()) return 0;
		if (1 == nums.size()) return nums[0];
		if (2 == nums.size()) return max(nums[0], nums[1]);

		int prePre = nums[0];
		int pre = max(nums[0], nums[1]);
		int cur;
		for (int i = 2; i < nums.size(); i++) {
			cur = max(pre, prePre + nums[i]);
			prePre = pre;
			pre = cur;
		}
		return cur;
	}
};