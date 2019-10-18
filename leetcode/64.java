class Solution {
    public int minPathSum(int[][] grid) {
        if (grid.length == 0) return 0;
        if (grid[0].length == 0) return 0;
        for (int row = 1; row < grid.length; row++) {
            grid[row][0] = grid[row - 1][0] + grid[row][0];
        }

        for (int col = 1; col < grid[0].length; col++) {
            grid[0][col] = grid[0][col] + grid[0][col - 1];
        }

        for (int row = 1; row < grid.length; row++) {
            for (int col = 1; col < grid[0].length; col++) {
                grid[row][col] = Integer.min(grid[row - 1][col], grid[row][col - 1]) + grid[row][col];
            }
        }

        return grid[grid.length - 1][grid[0].length - 1];
    }
}