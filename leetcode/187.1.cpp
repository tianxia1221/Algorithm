class Solution {
public:
	vector<string> findRepeatedDnaSequences(string s) {
		vector<string>  ret;
		unordered_map<string, int> mp;
		string word;
		//for(int i=0; i<s.length()-9; i++) {
		for (int i = 0; i + 9 < s.length(); i++) {
			word = s.substr(i, 10);
			if (mp.find(word) == mp.end()) {
				mp[word] = 1;
			}
			else mp[word] += 1;
		}

		for (auto it = mp.begin(); it != mp.end(); it++) {
			if (it->second > 1) ret.push_back(it->first);
		}

		return ret;
	}
};