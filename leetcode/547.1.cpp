class Solution {
public:
	int findCircleNum(vector<vector<int>>& M) {
		int ret = 0;
		int size = M.size();
		vector<bool> mark(size, false);
		for (int i = 0; i < size; i++) {
			if (false == mark[i]) {
				dfs(M, i, mark);
				ret++;
			}
		}
		return ret;
	}

	void dfs(vector<vector<int>>& M, int i, vector<bool>& mark) {
		mark[i] = true;
		for (int j = 0; j < mark.size(); j++) {
			if (M[i][j] && mark[j] == false) {
				dfs(M, j, mark);
			}
		}

	}
};