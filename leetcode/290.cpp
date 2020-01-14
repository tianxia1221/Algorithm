class Solution {
public:
	bool wordPattern(string pattern, string str) {
		unordered_map<string, char> map;
		unordered_set<char> set;
		string word;
		char cVal;
		int j = 0;
		str += " ";
		for (int i = 0; i < str.size(); i++) {

			if (str[i] == ' ') {
				if (j + 1 > pattern.size()) return false;

				if (map.find(word) != map.end()) {
					cVal = map[word];
					if (cVal != pattern[j]) return false;
				}
				else {
					cVal = pattern[j];
					if (set.find(cVal) != set.end()) return false;
					set.insert(cVal);
					map[word] = cVal;
				}
				word.clear();
				j++;
			}
			else {
				word += str[i];
			}
		}
		if (j < pattern.size()) return false;

		return true;
	}
};