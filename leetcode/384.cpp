//Runtime: 224 ms, faster than 16.10% of C++ online submissions for Shuffle an Array.
//Memory Usage: 31.2 MB, less than 21.43% of C++ online submissions for Shuffle an Array.
class Solution {
	vector<int> nums;
public:
	Solution(vector<int>& nums) {
		this->nums = nums;
	}

	/** Resets the array to its original configuration and return it. */
	vector<int> reset() {
		return nums;
	}

	/** Returns a random shuffling of the array. */
	vector<int> shuffle() {
		vector<int> ans(nums.size());
		vector<bool> mark(nums.size(), 0);
		int findIndex;
		for (int i = ans.size() - 1; i >= 0; i--) {
			int random = rand() % (i + 1) + 1;
			int n = 0;
			for (int j = 0; j < mark.size(); j++) {
				if (mark[j] == 0) {
					n++;
					if (n == random) {
						mark[j] = 1;
						ans[i] = nums[j];
						break;
					}
				}
			}
		}

		return ans;
	}
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */