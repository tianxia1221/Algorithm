class Solution {
    public int findCircleNum(int[][] M) {
        int[] mark = new int[M.length];
        Set<Integer> ret = new HashSet<>();
        for(int i=0; i<M.length; i++) {
            mark[i] = i;
        }
        for(int i=1; i<M.length; i++) {
            for(int j=0; j<i; j++) {
                if(M[i][j] == 1) {
                    int temp = mark[j];
                    for(int x = 0; x<M.length ; x++) {
                        if(mark[x] == temp) {
                            mark[x] = mark[i];
                        }
                    }
                    mark[j] = mark[i];
                }
            }
        }

        for(Integer i: mark) ret.add(i);

        return ret.size();
    }
}