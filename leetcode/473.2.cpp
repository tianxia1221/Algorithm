class Solution {
public:
	bool makesquare(vector<int>& nums) {

		if (0 == nums.size()) return false;

		vector<int> bucket(4, 0);
		int sum = 0;
		sort(nums.begin(), nums.end(), greater<int>());
		for (auto i : nums) sum += i;
		if (sum % 4 != 0) return false;

		return makesquare(nums, 0, sum / 4, bucket);
	}

	bool makesquare(vector<int>& nums, int i, int target, vector<int>& bucket) {
		if (i == nums.size()) {
			if (bucket[0] == target && bucket[1] == target &&
				bucket[2] == target && bucket[3] == target) return true;
		}

		for (int j = 0; j < 4; j++) {
			if (bucket[j] + nums[i] > target) continue;

			//put
			bucket[j] += nums[i];
			if (makesquare(nums, i + 1, target, bucket)) return true;
			bucket[j] -= nums[i];
		}
		return false;
	}

};