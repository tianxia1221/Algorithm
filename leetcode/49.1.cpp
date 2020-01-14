class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<string>> ret;
		map<string, vector<string>> m;
		string item;
		for (auto s : strs) {
			item = s;
			sort(s.begin(), s.end());
			if (m.find(s) == m.end()) {
				m[s] = vector<string>();
			}
			m[s].push_back(item);
		}

		for (auto it = m.begin(); it != m.end(); it++) {
			ret.push_back(it->second);
		}

		return ret;
	}
};