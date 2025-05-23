//Runtime: 8 ms, faster than 64.83% of C++ online submissions for Regular Expression Matching.
//Memory Usage: 8.9 MB, less than 69.49% of C++ online submissions for Regular Expression Matching.
class Solution {
public:
	bool isMatch(string s, string p) {
		vector<vector<char>> cache(s.size() + 1, vector<char>(p.size() + 1, -1));
		return helper(s, 0, p, 0, cache);
	}

	bool helper(string &s, int i, string & p, int j, vector<vector<char>> &cache) {

		if (cache[i][j] != -1)return cache[i][j];

		if (j == p.size()) return cache[i][j] = (i == s.size());

		bool first_match = (i < s.size() && (p[j] == s[i] || p[j] == '.'));

		//case 1: next charactor is *
		if (j + 1 < p.size() && p[j + 1] == '*') {
			//0 time
			if (helper(s, i, p, j + 2, cache))
				return cache[i][j] = true;

			//multipy times
			if (first_match && helper(s, i + 1, p, j, cache))
				return cache[i][j] = true;

			return cache[i][j] = false;
		}

        //case 2: not *
		if (first_match && helper(s, i + 1, p, j + 1, cache)) {
			return cache[i][j] = true;
        }
		return cache[i][j] = false;

	}
};