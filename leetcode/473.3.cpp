class Solution {
public:
	bool makesquare(vector<int>& nums) {

		if (0 == nums.size()) return false;

		int sum = 0;
		for (auto i : nums) sum += i;
		if (sum % 4 != 0) return false;

		int target = sum / 4;

		int all = 1 << nums.size();
		vector<int> oneSide;
		vector<int> twoSide;
		int index = 0;
		for (int i = 0; i < all; i++) {
			sum = 0;
			for (int j = 0; j < nums.size(); j++) {

				if (i&(1 << j)) {
					// if((i>>j)&1){
					sum += nums[j];
				}
				if (sum > target) break;
			}
			if (sum == target) {
				oneSide.push_back(i);
			}
		}

		for (int i = 0; i < oneSide.size(); i++) {
			for (int j = 0; j < oneSide.size(); j++) {
				if ((oneSide[i] & oneSide[j]) == 0) {
					twoSide.push_back(oneSide[i] | oneSide[j]);
				}
			}
		}

		for (int i = 0; i < twoSide.size(); i++) {
			for (int j = 0; j < twoSide.size(); j++)
				if ((twoSide[i] & twoSide[j]) == 0) return true;
		}

		return false;
	}
};