class Solution {
    public int findCircleNum(int[][] M) {
        int ret = 0;
        int size = M.length;
        Boolean[] mark = new Boolean[size];
        for(int i=0; i<size; i++){
            mark[i] = false;
        }

        for(int i=0; i<size; i++){
            if(mark[i] == false){
                bfs(i, mark, M);
                ret++;
            }
        }
        return ret;
    }

    void bfs(int s, Boolean[] mark, int[][] M){
        Queue<Integer> q = new LinkedList<>();
        q.add(s);
        mark[s] = true;
        while(0 != q.size()){
            s = q.remove();
            // mark[cur] = true;
            for(int i=0; i<M.length; i++){
                if(M[s][i] == 1 && mark[i] ==false) {
                    mark[i] = true;
                    q.add(i);
                }
            }
        }
        return;
    }
}