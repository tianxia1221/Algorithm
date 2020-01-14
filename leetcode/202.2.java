class Solution {

    class POS {
        int row;
        int col;

        POS() {
            row = 0;
            col = 0;
        }

        POS(int a, int b) {
            row = a;
            col = b;
        }
    }

    public int numIslands(char[][] grid) {
        int ret = 0;
        int row = grid.length;
        if (row == 0) return ret;
        int col = grid[row - 1].length;
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

    void bfs(char[][] grid, int row, int col) {
        POS cur;
        int top, bottom, left, right;
        int r, c;

        Queue<POS> q = new LinkedList<>();
        grid[row][col] = '2';
        q.add(new POS(row, col));
        while (0 != q.size()) {
            top = -1;
            bottom = -1;
            left = -1;
            right = -1;

            cur = q.remove();

            r = cur.row;
            c = cur.col;

            if (r - 1 >= 0) top = grid[r - 1][c];
            if (r + 1 <= grid.length - 1) bottom = grid[r + 1][c];
            if (c - 1 >= 0) left = grid[r][c - 1];
            if (c + 1 <= grid[r].length - 1) right = grid[r][c + 1];


            if (top == '1') {
                grid[r - 1][c] = '2';
                q.add(new POS(r - 1, c));
            }
            if (bottom == '1') {
                grid[r + 1][c] = '2';
                q.add(new POS(r + 1, c));
            }
            if (left == '1') {
                grid[r][c - 1] = '2';
                q.add(new POS(r, c - 1));
            }
            if (right == '1') {
                grid[r][c + 1] = '2';
                q.add(new POS(r, c + 1));
            }
        }
        return;
    }
};