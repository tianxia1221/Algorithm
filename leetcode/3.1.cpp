class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int ret = 0;
		int cache[256];
		for (int i = 0; i < 256; i++)
			cache[i] = 0;

		int begin = 0;
		int count = 0;
		for (int i = 0; i < s.size(); i++) {
			cache[s[i]]++;
			while (cache[s[i]] > 1) {
				cache[s[begin++]]--;
			}
			if (i - begin + 1 > ret) ret = i - begin + 1;
		}
		return ret;
	}
};