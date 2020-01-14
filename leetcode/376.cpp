class Solution {

private:
	enum STATE {
		BEGIN,
		UP,
		DOWN
	};

public:
	int wiggleMaxLength(vector<int>& nums) {
		int size = nums.size();
		if (size < 2) return size;
		STATE state = BEGIN;
		int count = 1;
		for (int i = 1; i < nums.size(); i++) {
			if (nums[i] == nums[i - 1]) continue;
			switch (state) {
			case BEGIN:
				nums[i] > nums[i - 1] ? state = UP : state = DOWN;
				count++;
				break;
			case UP:
				if (nums[i] < nums[i - 1]) {
					state = DOWN;
					count++;
				}
				break;
			case DOWN:
				if (nums[i] > nums[i - 1]) {
					state = UP;
					count++;
				}
				break;
			}
		}

		return count;
	}
};