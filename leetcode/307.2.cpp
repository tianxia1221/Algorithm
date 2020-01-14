class NumArray {
	vector<int> tree_nums;   //base 1 index
	vector<int> format_nums; //base 1 index
public:
	NumArray(vector<int>& nums) {
		tree_nums.resize(nums.size() + 1);
		format_nums.resize(nums.size() + 1);

		int j, count;
		for (int i = 1; i < nums.size() + 1; i++) {
			format_nums[i] = nums[i - 1];
			tree_nums[i] = 0;
			count = lowestBit(i);
			for (j = 0; j < count; j++) {
				tree_nums[i] += nums[i - j - 1];
			}
		}
	}

	void update(int i, int val) {
		update_node(i + 1, val - format_nums[i + 1]);
		format_nums[i + 1] = val;
	}

	int sumRange(int i, int j) {
		return sum(j + 1) - sum(i);
	}

	int lowestBit(int n) {
		return n & (-n);
	}

	void update_node(int i, int val) {

		int count = tree_nums.size();
		while (i < count) {
			tree_nums[i] += val;
			i += lowestBit(i);
		}

	}

	int sum(int i) {
		int ret = 0;
		while (i) {
			ret += tree_nums[i];
			i -= lowestBit(i);
		}
		return ret;
	}
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */