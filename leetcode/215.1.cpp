class cmp {

	bool operator() (int d1, int d2) {
		return d1 > d2;
	}
};
class Solution {

private:
	typedef bool (Solution::*cmp1)();
	bool compare(int d1, int d2) {
		return d1 > d2;
	}
public:

	int findKthLargest(vector<int>& nums, int k) {
		//priority_queue<int, vector<int>, cmp> data;
		priority_queue<int, vector<int>, greater<int>> data; //min statck
		//priority_queue<int, vector<int>, cmp1> data;
		for (int i : nums) {
			if (data.size() < k) {
				data.push(i);
			}
			else {
				if (i > data.top()) {
					data.push(i);
					data.pop();
				}
			}
		}

		return data.top();
	}

};