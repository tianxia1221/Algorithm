//Runtime: 26 ms, faster than 15.27% of Java online submissions for Longest Increasing Path in a Matrix.
//        Memory Usage: 37.3 MB, less than 100.00% of Java online submissions for Longest Increasing Path in a Matrix.
class Node implements Comparable<Node>{
    int x;
    int y;
    int val;
    public Node(int x, int y, int val) {
        this.x = x;
        this.y = y;
        this.val = val;
    }

    public int compareTo(Node that) {
        return that.val - val;
    }

}

class Solution {
    public int longestIncreasingPath(int[][] matrix) {
        int[] dx = {0, 0, -1, 1};
        int[] dy = {1, -1, 0, 0};
        int newx = 0;
        int newy = 0;

        int n = matrix.length;
        if(n == 0) return 0;
        int m = matrix[0].length;
        if(m == 0) return 0;

        int[][] memo = new int[n][m];
        int maxVal = 0;
        int curMaxVal = 0;
        PriorityQueue<Node> maxQ = new PriorityQueue<>(m*n);
        Node cur;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++) {
                maxQ.add(new Node(i, j, matrix[i][j]));
            }
        }

        while(maxQ.size() > 0) {
            cur = maxQ.poll();
            curMaxVal = 1;
            for(int i=0; i<4; i++){
                newx = cur.x + dx[i];
                newy = cur.y + dy[i];
                if(newx >= 0 && newx < n && newy >=0 && newy < m
                        && matrix[cur.x][cur.y] < matrix[newx][newy] && memo[newx][newy] != 0 ) {
                    curMaxVal = Math.max(curMaxVal, memo[newx][newy]+1);
                }
            }
            memo[cur.x][cur.y] = curMaxVal;
            maxVal = Math.max(maxVal, curMaxVal);
        }
        return maxVal;
    }
}