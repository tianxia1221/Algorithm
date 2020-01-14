class Solution {
public:
	bool canJump(vector<int>& nums) {
		int left = 0;
		int right = 0;

		while (right < nums.size() - 1) {
			right = max(right, left + nums[left]);

			if (left == right) {
				return false;
			}
			//[left, right) if (right < nums.size() - 1 ) return true;
			for (int i = left + 1; i < right && right < nums.size() - 1; i++) {
				if (i + nums[i] > right) right = i + nums[i];
			}

			left = right;
		}

		return true;
	}
};