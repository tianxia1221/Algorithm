class Solution {
public:
	vector<string> findRepeatedDnaSequences(string s) {
		vector<string>  ret;
		int memo[1048576];
		memset(memo, 0, sizeof(memo));

		int num = s.size() - 9;
		string word;
		for (int i = 0; i < num; i++) {
			word = s.substr(i, 10);
			change_word_to_int(word, memo);
		}

		for (int i = 0; i < 1048576; i++) {
			if (memo[i] > 1) {
				change_int_to_word(i, word);
				ret.push_back(word);
			}
		}
		return ret;
	}

	void change_word_to_int(const string & word, int* memo) {
		static int map[256];
		map['A'] = 0;
		map['C'] = 1;
		map['G'] = 2;
		map['T'] = 3;
		int value = 0;
		for (int i = 9; i >= 0; i--) {
			value = (value << 2) + map[word[i]];
		}
		memo[value]++;
	}

	void change_int_to_word(int value, string &word) {
		char map[4] = { 'A','C','G','T' };
		int index = 0;
		word.clear();
		for (int i = 0; i < 10; i++) {
			index = value & 3;
			value = value >> 2;
			word.append(1, map[index]);
		}
	}
};