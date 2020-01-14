class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int alen = A.size();
        int blen = B.size();
        int ret = 0;
        vector<vector<int>> dp(alen, vector<int>(blen, 0));
        for (int i = 0; i < alen; i++) {
            for (int j = 0; j < blen; j++) {
                if (A[i] == B[j]) {
                    i&&j ? dp[i][j] = dp[i - 1][j - 1] + 1 : dp[i][j] = 1;
                    ret = max(ret, dp[i][j]);
                }
            }
        }
        return ret;
    }
};

class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int alen = A.size();
        int blen = B.size();
        int ret = 0;
        vector<vector<int>> dp(alen, vector<int>(blen, 0));
        for (int i = 0; i < alen; i++) {
            if (A[i] == B[0]) {
                dp[i][0] = 1;
                ret = 1;
            }
        }

        for (int j = 1; j < blen; j++) {
            if (A[0] == B[j]) {
                dp[0][j] = 1;
                ret = 1;
            }
        }

        for (int i = 1; i < alen; i++) {
            for (int j = 1; j < blen; j++) {
                if (A[i] == B[j]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    ret = max(ret, dp[i][j]);
                }
            }
        }

        return ret;
    }
};

class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int alen = A.size();
        int blen = B.size();
        int ret = 0;
        vector<vector<int>> dp(alen, vector<int>(blen, 1));
        for (int i = 0; i < alen; i++) {
            if (A[i] != B[0]) {
                dp[i][0] = 0;
            }
            else {
                dp[i][0] = 1;
                ret = 1;
            }
        }

        for (int j = 1; j < blen; j++) {
            if (A[0] != B[j]) {
                dp[0][j] = 0;
            }
            else {
                dp[0][j] = 1;
                ret = 1;
            }
        }

        for (int i = 1; i < alen; i++) {
            for (int j = 1; j < blen; j++) {
                if (A[i] == B[j]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else {
                    dp[i][j] = 0;
                }
                ret = max(ret, dp[i][j]);
            }
        }

        return ret;
    }
};