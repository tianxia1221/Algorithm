class Solution {
    public int findCircleNum(int[][] M) {
        int ret = 0;
        int size = M.length;
        Boolean[] mark = new Boolean[size];
        for(int i=0; i<size; i++) mark[i] = false;
        for(int i=0; i<size; i++) {
            if(false == mark[i]) {
                dfs(M, i, mark);
                ret++;
            }
        }
        return ret;
    }

    void dfs(int[][] M, int i, Boolean[] mark) {
        mark[i] = true;
        for(int j=0; j<mark.length; j++) {
            if(M[i][j] == 1 && mark[j] == false) {
                dfs(M, j, mark);
            }
        }

    }
}