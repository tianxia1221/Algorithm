//Runtime: 84 ms, faster than 99.69% of C++ online submissions for 3Sum.
//Memory Usage: 14.6 MB, less than 98.82% of C++ online submissions for 3Sum.
class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& num) {
		vector<vector<int> > res;
		std::sort(num.begin(), num.end());
		for (int i = 0; i < num.size(); i++) {
			int target = -num[i];
			int front = i + 1;
			int back = num.size() - 1;
			while (front < back) {
				int sum = num[front] + num[back];
				if (sum < target)
					front++;
				else if (sum > target)
					back--;
				else {
					vector<int> triplet(3, 0);
					triplet[0] = num[i];
					triplet[1] = num[front];
					triplet[2] = num[back];
					res.push_back(move(triplet));

					front++;
					while (front < back && num[front] == num[front - 1]) front++;

					back--;
					while (front < back && num[back] == num[back + 1]) back--;
				}
			}

			while (i + 1 < num.size() && num[i + 1] == num[i])
				i++;

		}
		return res;
	}
};