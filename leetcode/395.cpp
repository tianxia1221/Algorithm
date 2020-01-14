//Runtime: 132 ms, faster than 27.86% of C++ online submissions for Longest Substring with At Least K Repeating Characters.
//	Memory Usage : 25.6 MB, less than 27.27% of C++ online submissions for Longest Substring with At Least K Repeating Characters
class Solution {
public:
	int longestSubstring(string s, int k) {
		return longestSubstring(s, 0, s.length() - 1, k);
	}

	int longestSubstring(string &s, int start, int end, int k) {
		int ans = 0;
		int curAns = 0;
		if (end < start) return 0;

		vector<int> count(256, 0);

		for (int i = start; i <= end; i++) {
			count[s[i]]++;
		}

		for (int i = start; i <= end; i++) {

			if (count[s[i]] != 0 && count[s[i]] < k) {
				curAns = longestSubstring(s, start, i - 1, k);
				ans = max(ans, curAns);
				if (ans > end - i) return ans;
				curAns = longestSubstring(s, i + 1, end, k);
				ans = max(ans, curAns);
				return ans;
			}
		}

		return end - start + 1;
	}
};

//Runtime: 4 ms, faster than 84.94% of C++ online submissions for Longest Substring with At Least K Repeating Characters.
//	Memory Usage : 8.8 MB, less than 54.55% of C++ online submissions for Longest Substring with At Least K Repeating Characters.
class Solution {
public:
	int longestSubstring(string s, int k) {
		return longestSubstring(s, 0, s.length() - 1, k);
	}

	int longestSubstring(string &s, int start, int end, int k) {
		int ans = 0;
		int curAns = 0;
		if (end < start) return 0;

		int pre = start;
		bool isDivided = false;

		vector<int> count(26, 0);


		for (int i = start; i <= end; i++) {
			count[s[i] - 'a']++;
		}

		for (int i = start; i <= end; i++) {

			if (count[s[i] - 'a'] != 0 && count[s[i] - 'a'] < k) {
				isDivided = true;
				if (i - pre > ans) {
					curAns = longestSubstring(s, pre, i - 1, k);
				}
				ans = max(ans, curAns);
				if (ans > end - i) return ans;
				pre = i + 1;

			}
		}

		if (pre > start) {
			curAns = longestSubstring(s, pre, end, k);
			ans = max(ans, curAns);
		}

		return isDivided ? ans : end - start + 1;
	}
};