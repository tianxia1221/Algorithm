//Runtime: 36 ms, faster than 82.45% of C++ online submissions for Range Sum Query - Mutable.
//Memory Usage: 18.5 MB, less than 100.00% of C++ online submissions for Range Sum Query - Mutable.
class NumArray {
private:
	vector<int> val;
	int count;
public:
	NumArray(vector<int>& nums) {

		if (nums.size() == 0) return;
		count = nums.size();
		unsigned int size = highOne(count);
		val.resize(size);
		build_segment_tree(nums, 0, nums.size() - 1, 0);

	}

	unsigned int highOne(int n) {
		int ret = n;
		// while(n){
		//     ret = n;
		//     n = n & (n -1);
		// }
		return ret << 2;
	}

	void update(int i, int val) {
		update(i, val, 0, 0, count - 1);
	}

	void update(int i, int value, int pos, int left, int right) {

		if (left == right) {
			val[pos] = value;
			return;
		}

		int mid = left + (right - left) / 2;
		int childLeftPos = 2 * pos + 1;
		int childRightPos = 2 * pos + 2;
		if (i > mid) update(i, value, childRightPos, mid + 1, right);
		else update(i, value, childLeftPos, left, mid);
		val[pos] = val[childLeftPos] + val[childRightPos];
	}

	int sumRange(int i, int j) {
		return sumRange(i, j, 0, 0, count - 1);
	}

	int sumRange(int start, int end, int pos, int left, int right) {


		if (start <= left) start = left;
		if (end >= right) end = right;

		if (start == left && end == right) return val[pos];

		int mid = left + (right - left) / 2;
		int childLeftPos = 2 * pos + 1;
		int childRightPos = 2 * pos + 2;

		if (end <= mid)  return sumRange(start, end, childLeftPos, left, mid);
		else if (start > mid) return sumRange(start, end, childRightPos, mid + 1, right);

		return  sumRange(start, end, childLeftPos, left, mid) + sumRange(start, end, childRightPos, mid + 1, right);
	}

	void build_segment_tree(vector<int>& nums, int left, int right, int pos) {
		if (left == right) {
			val[pos] = nums[left];
			return;
		}

		int mid = left + (right - left) / 2;
		int childLeftPos = 2 * pos + 1;
		int childRightPos = 2 * pos + 2;
		build_segment_tree(nums, left, mid, childLeftPos);
		build_segment_tree(nums, mid + 1, right, childRightPos);
		val[pos] = val[childLeftPos] + val[childRightPos];
	}
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */
//Runtime: 44 ms, faster than 49.85% of C++ online submissions for Range Sum Query - Mutable.
//Memory Usage: 18.8 MB, less than 100.00% of C++ online submissions for Range Sum Query - Mutable.

 class NumArray {
 private:
 	vector<int> val;
 	int count;
 public:
 	NumArray(vector<int>& nums) {
 		count = nums.size();
         if (count == 0) return;
 		unsigned int size = count << 2;
 		val.resize(size);
 		build_segment_tree(nums, 0, nums.size() - 1, 0);
 	}

 	void update(int i, int val) {
 		update(i, val, 0, 0, count - 1);
 	}

 	void update(int i, int value, int pos, int left, int right) {

 		if (left == right) {
 			val[pos] = value;
 			return;
 		}

         int mid = left + (right - left) / 2;
 		int childLeftPos = 2 * pos + 1;
 		int childRightPos = 2 * pos + 2;
 		if (i > mid) update(i, value, childRightPos, mid + 1, right);
 		else update(i, value, childLeftPos, left, mid);

         val[pos] = val[childLeftPos] + val[childRightPos];
 	}

 	int sumRange(int i, int j) {
 		return sumRange(i, j, 0, 0, count - 1);
 	}

 	int sumRange(int start, int end, int pos, int left, int right) {

 		if (start == left && end == right) return val[pos];

 		int mid = left + (right - left) / 2;
 		int childLeftPos = 2 * pos + 1;
 		int childRightPos = 2 * pos + 2;

 		if (end <= mid)  return sumRange(start, end, childLeftPos, left, mid);
 		else if (start > mid) return sumRange(start, end, childRightPos, mid + 1, right);

 		return  sumRange(start, mid, childLeftPos, left, mid) + sumRange(mid+1, end, childRightPos, mid + 1, right);
 	}

 	void build_segment_tree(vector<int>& nums, int left, int right, int pos) {
 		if (left == right) {
 			val[pos] = nums[left];
 			return;
 		}

 		int mid = left + (right - left) / 2;
 		int childLeftPos = 2 * pos + 1;
 		int childRightPos = 2 * pos + 2;
 		build_segment_tree(nums, left, mid, childLeftPos);
 		build_segment_tree(nums, mid + 1, right, childRightPos);
 		val[pos] = val[childLeftPos] + val[childRightPos];
 	}
 };
