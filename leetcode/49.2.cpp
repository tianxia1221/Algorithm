class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<string>> ret;
		map<vector<int>, vector<string>> m;
		vector<int> key(128);
		for (auto s : strs) {
			changStrToMapKey(s, key);
			if (m.find(key) == m.end()) {
				m[key] = vector<string>();
			}
			m[key].push_back(s);
		}

		for (auto it = m.begin(); it != m.end(); it++) {
			ret.push_back(it->second);
		}

		return ret;
	}

	void changStrToMapKey(string &s, vector<int> &key) {
		for (int i = 0; i < key.size(); i++)
			key[i] = 0;
		for (int i = 0; i < s.size(); i++)
			key[s[i] - 'a']++;
	}
};