class Solution {
public:
	int findContentChildren(vector<int>& g, vector<int>& s) {
		sort(g.begin(), g.end());
		sort(s.begin(), s.end());
		int j = 0;
		int count = 0;
		for (int i = 0; i < g.size(); i++) {
			for (; j < s.size(); j++) {
				if (s[j] >= g[i]) {
					j++;
					count++;
					break;
				}
			}
		}
		return i;
	}
};