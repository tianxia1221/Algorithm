class Solution {

public:
	int numIslands(vector<vector<char>>& grid) {
		int ret = 0;
		int row = grid.size();
		if (row == 0) return ret;
		int col = grid[row - 1].size();
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (grid[i][j] == '1') {
					bfs(grid, i, j);
					ret++;
				}
			}
		}
		return ret;
	}

	void bfs(vector<vector<char>>& grid, int row, int col) {

		pair<int, int> cur;
		int top, bottom, left, right;
		int r, c;

		queue<pair<int, int>> q;
		grid[row][col] = '2';
		q.push(pair<int, int>(row, col));
		while (!q.empty()) {
			top = -1;
			bottom = -1;
			left = -1;
			right = -1;

			cur = q.front();
			q.pop();

			r = cur.first;
			c = cur.second;

			if (r - 1 >= 0) top = grid[r - 1][c];
			if (r + 1 <= grid.size() - 1) bottom = grid[r + 1][c];
			if (c - 1 >= 0) left = grid[r][c - 1];
			if (c + 1 <= grid[r].size() - 1) right = grid[r][c + 1];


			if (top == '1') { grid[r - 1][c] = '2'; q.push(pair<int, int>(r - 1, c)); }
			if (bottom == '1') { grid[r + 1][c] = '2'; q.push(pair<int, int>(r + 1, c)); }
			if (left == '1') { grid[r][c - 1] = '2'; q.push(pair<int, int>(r, c - 1)); }
			if (right == '1') { grid[r][c + 1] = '2'; q.push(pair<int, int>(r, c + 1)); }
		}
		return;
	}
};