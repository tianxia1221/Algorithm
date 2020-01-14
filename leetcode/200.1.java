class Solution {

    public int numIslands(char[][] grid) {
        int ret = 0;
        if (grid.length == 0 || grid[0].length == 0) return 0;
        boolean[][] mark = new boolean[grid.length][grid[0].length];
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                mark[i][j] = false;
            }
        }

        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                if (mark[i][j] == false && grid[i][j] == '1') {
                    dfs(i, j, grid, mark);
                    ret++;
                }
            }
        }
        return ret;
    }

    void dfs(int x, int y, char[][] grid, boolean[][] mark) {
        int xlen = grid.length;
        int ylen = grid[0].length;
        int[] xmove = new int[]{0, 0, -1, 1};
        int[] ymove = new int[]{-1, 1, 0, 0};
        int xnew, ynew;
        mark[x][y] = true;
        for (int i = 0; i < 4; i++) {
            xnew = x + xmove[i];
            ynew = y + ymove[i];
            if (xnew >= 0 && xnew < xlen && ynew >= 0 && ynew < ylen
                    && grid[xnew][ynew] == '1' && mark[xnew][ynew] == false) {
                dfs(xnew, ynew, grid, mark);
            }
        }
    }
};