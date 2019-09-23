class Solution {
public:
	vector<int> countSmaller(vector<int>& nums) {
		vector<int> result(nums.size());;
		vector<pair<int, int>> vec(nums.size());
		for (int i = 0; i < nums.size(); i++) {
			vec[i] = pair<int, int>(nums[i], i);
		}
		merge_sore(vec, result);
		return result;
	}

	void merge_sore(vector<pair<int, int>>& vec, vector<int> &result) {
		if (vec.size() <= 1) return;

		int mid = vec.size() / 2;
		vector<pair<int, int>> vec1;
		vector<pair<int, int>> vec2;
		for (int i = 0; i < mid; i++) {
			vec1.push_back(vec[i]);
		}
		merge_sore(vec1, result);

		for (int i = mid; i < vec.size(); i++) {
			vec2.push_back(vec[i]);
		}
		merge_sore(vec2, result);

		vec.clear();
		merge(vec1, vec2, vec, result);
	}

	void merge(vector<pair<int, int>>& vec1, vector<pair<int, int>>& vec2, vector<pair<int, int>>& vec, vector<int> &result) {
		int i = 0, j = 0;
		while (i < vec1.size() && j < vec2.size()) {
			if (vec1[i].first > vec2[j].first) {
				vec.push_back(vec2[j++]);
			}
			else {
				vec.push_back(vec1[i]);
				result[vec1[i].second] += j;
				i++;
			}
		}

		for (; i < vec1.size(); i++) {
			vec.push_back(vec1[i]);
			result[vec1[i].second] += j;
		}

		for (; j < vec2.size(); j++) {
			vec.push_back(vec2[j]);
		}

	}
};