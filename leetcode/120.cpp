class Solution {
public:
	int minimumTotal(vector<vector<int>>& triangle) {

		if (0 == triangle.size()) return 0;

		vector<int> dp(triangle[triangle.size() - 1]);

		for (int i = triangle.size() - 2; i >= 0; i--) {

			for (int j = 0; j < triangle[i].size(); j++) {
				dp[j] = min(dp[j], dp[j + 1]) + triangle[i][j];
			}
		}

		return dp[0];
	}
};

class Solution {
public:
	int minimumTotal(vector<vector<int>>& triangle) {

		if (0 == triangle.size()) return 0;

		//  vector<int> dp(triangle[triangle.size() - 1]);

		for (int i = triangle.size() - 2; i >= 0; i--) {

			for (int j = 0; j < triangle[i].size(); j++) {
				triangle[i][j] = min(triangle[i + 1][j], triangle[i + 1][j + 1]) + triangle[i][j];
			}
		}

		return triangle[0][0];
	}
};