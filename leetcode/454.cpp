//Runtime: 180 ms, faster than 67.58% of C++ online submissions for 4Sum II.
//Memory Usage: 28.4 MB, less than 86.36% of C++ online submissions for 4Sum II.
class Solution {
public:
	int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
		int res = 0;
		unordered_map<int, int> map1;
		constructMapAB(A, B, map1);
		processCD(C, D, map1, res);

		return res;
	}

	void constructMapAB(vector<int>& A, vector<int>& B, unordered_map<int, int> & map) {
		int target = 0;
		for (int i = 0; i < A.size(); i++) {
			for (int j = 0; j < B.size(); j++) {
				target = A[i] + B[j];
				if (map.find(target) == map.end()) {
					map[target] = 1;
				}
				else {
					map[target]++;
				}
			}
		}
	}

	void processCD(vector<int>& A, vector<int>& B, unordered_map<int, int> &map, int &res) {
		int target = 0;
		for (int i = 0; i < A.size(); i++) {
			for (int j = 0; j < B.size(); j++) {
				target = -A[i] - B[j];
				if (map.find(target) != map.end()) {
					res += map[target];
				}
			}
		}
	}
};