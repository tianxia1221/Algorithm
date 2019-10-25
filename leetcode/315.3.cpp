class Solution {

	class BIT {
	private:
		vector<int> tree;

	public:
		BIT(int n) {
			tree.resize(n);
			for (int i = 0; i < n; i++) tree[i] = 0;
		}

		void update_node(int i, int val) {
			int count = tree.size();
			while (i < count) {
				tree[i] += val;
				i += i & (-i);
			}
		}

		int sum(int i) {
			int ret = 0;
			while (i > 0) {
				ret += tree[i];
				i -= i & (-i);
			}
			return ret;
		}
	};

public:
	vector<int> countSmaller(vector<int>& nums) {
		vector<int> ret(nums.size());
		set<int> noDupNums(nums.begin(), nums.end());
		map<int, int> hmap;
		int i = 0;
		for (auto val : noDupNums) hmap[val] = ++i;

		BIT bitOpt(hmap.size() + 1);

		int index;
		for (int i = nums.size() - 1; i >= 0; i--) {
			index = hmap[nums[i]];
			bitOpt.update_node(index, 1);
			ret[i] = bitOpt.sum(index - 1);
		}

		return ret;
	}
};