class Solution {
public:
	bool makesquare(vector<int>& nums) {
		vector<bool> visited(nums.size(), false);
		if (0 == nums.size()) return false;

		int sum = 0;
		for (auto i : nums) sum += i;
		if (sum % 4 != 0) return false;

		int target = sum / 4;

		sort(nums.begin(), nums.end());
		return dfs(nums, nums.size() - 1, target, visited) && dfs(nums, nums.size() - 1, target, visited) && dfs(nums, nums.size() - 1, target, visited);
	}

	bool dfs(vector<int>& nums, int end, int target, vector<bool>& visited) {
		for (int i = end; i >= 0; i--) {
			if (visited[i]) continue;

			visited[i] = true;
			target -= nums[i];
			if (0 == target) {
				return true;
			}
			if (target > 0) {
				if (dfs(nums, i - 1, target, visited)) {
					return true;
				}
				//trace back
				visited[i] = false;
				target += nums[i];
				return dfs(nums, i - 1, target, visited);
			}

			//trace back
			visited[i] = false;
			target += nums[i];

		}
		return false;
	}
};

class Solution {
public:
	bool makesquare(vector<int>& nums) {
		if (0 == nums.size()) return false;

		int sum = 0;
		for (auto i : nums) sum += i;
		if (sum % 4 != 0) return false;

		int target = sum / 4;

		sort(nums.begin(), nums.end());
		return dfs(nums, nums.size() - 1, target) && dfs(nums, nums.size() - 1, target) && dfs(nums, nums.size() - 1, target);
	}

	bool dfs(vector<int>& nums, int end, int target) {
		for (int i = end; i >= 0; i--) {

			int bk = nums[i];
			if (nums[i] == -1) continue;

			//select ith element
			target -= nums[i];
			nums[i] = -1;

			if (0 == target) return true;

			if (target > 0) {
				if (dfs(nums, i - 1, target)) {
					return true;
				}
				//trace back
				nums[i] = bk;
				target += nums[i];
				return dfs(nums, i - 1, target);
			}

			//trace back
			nums[i] = bk;
			target += nums[i];
		}

		return false;
	}
};