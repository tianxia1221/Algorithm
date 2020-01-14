class Solution {
public:
	int numIslands(vector<vector<char>>& grid) {
		int ret = 0;
		if (grid.size() == 0 || grid[0].size() == 0) return 0;
		vector<vector<bool>> mark(grid.size(), vector<bool>(grid[0].size(), false));
		for (int i = 0; i < grid.size(); i++) {
			for (int j = 0; j < grid[0].size(); j++) {
				if (mark[i][j] == false && grid[i][j] == '1') {
					dfs(i, j, grid, mark);
					ret++;
				}
			}
		}
		return ret;
	}

	void dfs(int x, int y, vector<vector<char>>& grid, vector<vector<bool>>& mark) {
		int xlen = grid.size();
		int ylen = grid[0].size();
		static const int xmove[4] = { 0, 0, -1, 1 };
		static const int ymove[4] = { -1,1, 0, 0 };
		int xnew, ynew;
		mark[x][y] = true;
		for (int i = 0; i < 4; i++) {
			xnew = x + xmove[i];
			ynew = y + ymove[i];
			if (xnew >= 0 && xnew < xlen && ynew >= 0 && ynew < ylen
				&& grid[xnew][ynew] == '1'&& mark[xnew][ynew] == false) {
				dfs(xnew, ynew, grid, mark);
			}

		}
	}
};