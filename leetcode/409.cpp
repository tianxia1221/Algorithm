class Solution {
public:
	int longestPalindrome(string s) {
		int o = 0;
		bool isSingle = false;
		int t;
		vector<int> v(256, 0);
		for (int i = 0; i < s.size(); ++i)
		{
			++v[s[i]];

		}
		for (int i = 0; i < 256; ++i) {

			if (v[i] % 2)
				isSingle = true;
			o += 2 * (v[i] / 2);
		}
		if (isSingle) ++o;
		return o;
	}
};