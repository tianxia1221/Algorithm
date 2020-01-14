class Solution {
public:
	string removeKdigits(string num, int k) {
		vector<char> s;
		string result;
		char cur;

		for (int i = 0; i < num.length(); i++) {
			cur = num[i];
			while (s.size() > 0 && s.back() > cur && k-- > 0) s.pop_back();
			if (!s.empty() || cur != '0') s.push_back(cur);
		}

		while (!s.empty() && k-- > 0) s.pop_back();

		for (char c : s) result += c;

		if (result.empty()) return "0";

		return result;
	}
};