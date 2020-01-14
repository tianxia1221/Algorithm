
//Runtime: 20 ms, faster than 50.67% of C++ online submissions for Delete Operation for Two Strings.
//Memory Usage : 14.3 MB, less than 55.56% of C++ online submissions for Delete Operation for Two Strings.
class Solution {
public:
	int minDistance(string word1, string word2) {
		int len1 = word1.size();
		int len2 = word2.size();
		vector<vector<int>> dp(len1, vector<int>(len2, 2));

		if (!len1) return len2;
		if (!len2) return len1;

		for (int i = 0; i < len1; i++) {
			if (word1[i] == word2[0]) dp[i][0] = i;
			else {
				i == 0 ? dp[i][0] = 2 : dp[i][0] = (dp[i - 1][0] + 1);
			}
		}

		for (int j = 1; j < len2; j++) {
			if (word1[0] == word2[j]) dp[0][j] = j;
			else {
				dp[0][j] = dp[0][j - 1] + 1;
			}
		}

		for (int i = 1; i < len1; i++) {
			for (int j = 1; j < len2; j++) {
				if (word1[i] == word2[j]) {
					dp[i][j] = dp[i - 1][j - 1];
				}
				else {
					dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
				}
			}
		}

		return dp[len1 - 1][len2 - 1];
	}
};

//Runtime: 16 ms, faster than 78.54% of C++ online submissions for Delete Operation for Two Strings.
//Memory Usage : 14.2 MB, less than 55.56% of C++ online submissions for Delete Operation for Two Strings.
class Solution {
public:
	int minDistance(string word1, string word2) {
		int len1 = word1.size();
		int len2 = word2.size();

		if (!len1) return len2;
		if (!len2) return len1;
		int len = helper(word1, word2);
		return len1 + len2 - 2 * len;

	}
	int helper(const string &A, const string &B) {
		int alen = A.size();
		int blen = B.size();
		int ret = 0;
		vector<vector<int>> dp(alen, vector<int>(blen, 1));
		for (int i = 0; i < alen; i++) {
			if (A[i] != B[0]) {
				dp[i][0] = 0;
			}
			else {
				ret = 1;
				break;
			}
		}

		for (int j = 0; j < blen; j++) {
			if (A[0] != B[j]) {
				dp[0][j] = 0;
			}
			else {
				ret = 1;
				break;
			}
		}

		for (int i = 1; i < alen; i++) {
			for (int j = 1; j < blen; j++) {
				if (A[i] == B[j]) {
					dp[i][j] = dp[i - 1][j - 1] + 1;
				}
				else {
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
				}
				ret = max(ret, dp[i][j]);
			}
		}

		return ret;
	}
};