//Runtime: 16 ms, faster than 34.08% of C++ online submissions for Edit Distance.
//Memory Usage : 11.2 MB, less than 62.50% of C++ online submissions for Edit Distance.
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++) {
            dp[i][0] = i;
        }
        for (int j = 1; j <= n; j++) {
            dp[0][j] = j;
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else {
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j])) + 1;
                }
            }
        }
        return dp[m][n];
    }
};

//Runtime: 12 ms, faster than 68.81% of C++ online submissions for Edit Distance.
//Memory Usage : 11.5 MB, less than 25.00% of C++ online submissions for Edit Distance.
class Solution {

public:
    int minDistance(string word1, string word2) {

        unsigned int len1 = word1.length();
        unsigned int len2 = word2.size();
        vector<vector<int>> dp(len1, vector<int>(len2, -1));
        if (len1 == 0) return len2;
        if (len2 == 0) return len1;

        return helper(word1, len1 - 1, word2, len2 - 1, dp);
    }

    int helper(string &word1, unsigned int end1, string &word2, unsigned int end2, vector<vector<int>> &dp) {



        if (end1 == -1) return end2 + 1;
        if (end2 == -1) return end1 + 1;

        if (dp[end1][end2] != -1) return dp[end1][end2];

        if (word1[end1] == word2[end2])
            return helper(word1, end1 - 1, word2, end2 - 1, dp);

        //delete last char
        int ret1 = helper(word1, end1 - 1, word2, end2, dp);
        // replace last char
        int ret2 = helper(word1, end1 - 1, word2, end2 - 1, dp);
        //insert a new char from backend
        int ret3 = helper(word1, end1, word2, end2 - 1, dp);

        return dp[end1][end2] = min(min(ret1, ret2), ret3) + 1;

    }
};

//Runtime: 36 ms, faster than 8.27% of C++ online submissions for Edit Distance.
//Memory Usage : 22.1 MB, less than 6.25% of C++ online submissions for Edit Distance.
class Solution {
    unordered_map<long, int> hm;
public:
    int minDistance(string word1, string word2) {
        unsigned int len1 = word1.length();
        unsigned int len2 = word2.size();
        if (len1 == 0) return len2;
        if (len2 == 0) return len1;
        cout << sizeof(int);
        return helper(word1, len1 - 1, word2, len2 - 1);
    }

    int helper(string &word1, unsigned int end1, string &word2, unsigned int end2) {


        long key = ((long)end1 << sizeof(int) * 8) | end2;

        if (hm.find(key) != hm.end()) return hm[key];

        if (end1 == -1) return end2 + 1;
        if (end2 == -1) return end1 + 1;
        if (word1[end1] == word2[end2])
            return helper(word1, end1 - 1, word2, end2 - 1);

        //delete last char
        int ret1 = helper(word1, end1 - 1, word2, end2);
        // replace last char
        int ret2 = helper(word1, end1 - 1, word2, end2 - 1);
        //insert a new char from backend
        int ret3 = helper(word1, end1, word2, end2 - 1);

        hm[key] = min(min(ret1, ret2), ret3) + 1;

        return hm[key];

    }
};

//Runtime: 700 ms, faster than 5.04% of C++ online submissions for Edit Distance.
//Memory Usage : 473.1 MB, less than 6.25% of C++ online submissions for Edit Distance.
class Solution {
    unordered_map<string, int> hm;
public:
    int minDistance(string word1, string word2) {

        string key = word1 + "#" + word2;

        if (hm.find(key) != hm.end()) return hm[key];

        int len1 = word1.length();
        int len2 = word2.size();
        if (len1 == 0) return len2;
        if (len2 == 0) return len1;
        if (word1[len1 - 1] == word2[len2 - 1])
            return minDistance(word1.substr(0, len1 - 1), word2.substr(0, len2 - 1));

        //delete last char
        int ret1 = minDistance(word1.substr(0, len1 - 1), word2);
        // replace last char
        int ret2 = minDistance(word1.substr(0, len1 - 1), word2.substr(0, len2 - 1));
        //insert a new char from backend
        int ret3 = minDistance(word1, word2.substr(0, len2 - 1));

        hm[key] = min(min(ret1, ret2), ret3) + 1;

        return hm[key];

    }
};