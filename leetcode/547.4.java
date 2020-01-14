
class Solution {
    public int findCircleNum(int[][] M) {
        DisjoinSet ds = new DisjoinSet(M.length);
        for(int i=1; i<M.length; i++) {
            for(int j=0; j<i; j++) {
                if(1 == M[i][j]) ds.unionelms(i,j);
            }
        }
        return ds.getCount();
    }
}

class DisjoinSet{
    private int[] ids;
    private int[] size;
    private int count;
    public DisjoinSet(int n) {
        ids = new int[n];
        size = new int[n];
        for(int i=0; i<n; i++) {
            ids[i] = i;
            size[i] = 1;
            count = n;
        }
    }

    public void unionelms(int i, int j){

        int pi = find(i);
        int pj = find(j);

        if(pi == pj) return;

        if(size[pi] < size[pj]) {
            ids[pi] = pj;
            size[pj] += size[pi];

        }
        else {
            ids[pj] = pi;
            size[pi] += size[pj];
        }
        count--;

    }

    private int find(int i) {
        while(i != ids[i]) {
            ids[i] = ids[ids[i]];
            i = ids[i];
        }
        return i;
    }

    public int getCount() {
        return count;
    }
}
