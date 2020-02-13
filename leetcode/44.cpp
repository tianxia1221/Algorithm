class Solution {
public:
	bool isMatch(string s, string p) {
		vector<vector<char>> dp(s.length() + 1, vector<char>(p.length() + 1, '@'));
		return isMatch(s, 0, p, 0, dp);
	}

	bool isMatch(string& s, int i, string& p, int j, vector<vector<char>>& dp) {
		int m = s.size();
		int n = p.size();
		// 1. both s and p are empty;
		if (i == m && j == n) return dp[i][j] = true;

		if (dp[i][j] != '@') return dp[i][j];

		// 2. s is empty, p is not
		if (i == m) {
			if (p[j] == '*') {
				return dp[i][j] = isMatch(s, i, p, j + 1, dp);
			}
			else {
				return dp[i][j] = false;
			}
		}
		// 3. p is empty, s is not
		if (j == n) return dp[i][j] = false;

		// 4. both s and p are not empty;
		if (j == p.size() - 1 && p[j] == '*') return dp[i][j] = true;

		if (p[j] == '?') return dp[i][j] = isMatch(s, i + 1, p, j + 1, dp);
		else if (p[j] == '*') {

			if (j + 1 < n && p[j + 1] == '*') return dp[i][j] = isMatch(s, i, p, j + 1, dp);

			for (; i < m; i++) {
				if (isMatch(s, i, p, j + 1, dp))
					return dp[i][j] = true;
			}
			return dp[i][j] = false;
		}
		// p[j] != '*' && p[j] != '?'
		return  dp[i][j] = (s[i] == p[j] && isMatch(s, i + 1, p, j + 1, dp));
	}
};